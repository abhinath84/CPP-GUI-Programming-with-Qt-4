#ifndef CGPLOTSETTINGS_H
#define CGPLOTSETTINGS_H


/*
 * The CGPlotSettings class specifies the range of the x and y axes and the number
 * of ticks for these axes.
 * By convention, numXTicks and numYTicks are off by one; if numXTicks is 5, Plotter
 * will actually draw 6 tick marks on the x axis. This simplifies the calculations
 * later on.
*/
class CGPlotSettings
{
public:
    CGPlotSettings();

    void scroll(int dx, int dy);
    void adjust();
    double spanX() const { return maxX - minX; }
    double spanY() const { return maxY - minY; }

public:
    double minX;
    double maxX;
    int numXTicks;
    double minY;
    double maxY;
    int numYTicks;

private:
    static void adjustAxis(double &min, double &max, int &numTicks);
};

#endif // CGPLOTSETTINGS_H
