#include "CGPlotSettings.h"

#include <cmath>

/*
 * The PlotSettings constructor initializes both axes to the range 0 to 10 with
 * 5 tick marks.
*/
CGPlotSettings::CGPlotSettings()
{
    minX = 0.0;
    maxX = 10.0;
    numXTicks = 5;

    minY = 0.0;
    maxY = 10.0;
    numYTicks = 5;
}

/*
 * The scroll() function increments (or decrements) minX , maxX , minY , and maxY by
 * the interval between two ticks times a given number. This function is used to
 * implement scrolling in Plotter::keyPressEvent() .
*/
void CGPlotSettings::scroll(int dx, int dy)
{
    double stepX = spanX() / numXTicks;
    minX += dx * stepX;
    maxX += dx * stepX;

    double stepY = spanY() / numYTicks;
    minY += dy * stepY;
    maxY += dy * stepY;
}

/*
 * The adjust() function is called from mouseReleaseEvent() to round the minX , maxX ,
 * minY , and maxY values to “nice” values and to determine the number of ticks
 * appropriate for each axis. The private function adjustAxis() does its work one
 * axis at a time.
*/
void CGPlotSettings::adjust()
{
    adjustAxis(minX, maxX, numXTicks);
    adjustAxis(minY, maxY, numYTicks);
}

/*
 * The adjustAxis() function converts its min and max parameters into “nice”
 * numbers and sets its numTicks parameter to the number of ticks it calculates
 * to be appropriate for the given [ min , max ] range. Because adjustAxis() needs to
 * modify the actual variables ( minX , maxX , numXTicks , etc.) and not just copies, its
 * parameters are non-const references.
 * Most of the code in adjustAxis() simply attempts to determine an appropriate
 * value for the interval between two ticks (the “step”). To obtain nice numbers
 * along the axis, we must select the step with care. For example, a step value of
 * 3.8 would lead to an axis with multiples of 3.8, which is difficult for people to
 * relate to. For axes labeled in decimal notation, “nice” step values are numbers
 * of the form 10^n , 2· 10^n , or 5· 10^n.
 * We start by computing the “gross step”, a kind of maximum for the step value.
 * Then we find the corresponding number of the form 10 that is smaller than
 * or equal to the gross step. We do this by taking the decimal logarithm of the
 * gross step, rounding that value down to a whole number, then raising 10^n to
 * the power of this rounded number. For example, if the gross step is 236, we
 * compute log 236 = 2.37291...; then we round it down to 2 and obtain 10^2 = 100
 * as the candidate step value of the form 10^n.
 * Once we have the first candidate step value, we can use it to calculate the
 * other two candidates: 2·10^n and 5·10^n . For the example above, the two other
 * candidates are 200 and 500. The 500 candidate is larger than the gross step, so
 * we can’t use it. But 200 is smaller than 236, so we use 200 for the step size in
 * this example.
 * It’s fairly easy to derive numTicks , min , and max from the step value. The new min
 * value is obtained by rounding the original min down to the nearest multiple
 * of the step, and the new max value is obtained by rounding up to the nearest
 * multiple of the step. The new numTicks is the number of intervals between the
 * rounded min and max values. For example, if min is 240 and max is 1184 upon
 * entering the function, the new range becomes [200, 1200], with 5 tick marks.
 * This algorithm will give suboptimal results in some cases. A more sophisticated
 * algorithm is described in Paul S. Heckbert’s article “Nice Numbers for Graph
 * Labels” published in Graphics Gems (ISBN 0-12-286166-3).
*/
void CGPlotSettings::adjustAxis(double &min, double &max, int &numTicks)
{
    const int MinTicks = 4;
    double grossStep = (max - min) / MinTicks;
    double step = pow(10.0, floor(log10(grossStep)));

    if (5 * step < grossStep)
        step *= 5;
    else if (2 * step < grossStep)
        step *= 2;

    numTicks = int(ceil(max / step) - floor(min / step));
    if (numTicks < MinTicks)
        numTicks = MinTicks;

    min = floor(min / step) * step;
    max = ceil(max / step) * step;
}
