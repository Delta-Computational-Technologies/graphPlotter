#ifndef GRAPH_PLOTTER_H
#define GRAPH_PLOTTER_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template <class T> class graphPlotter
{
    public:
        graphPlotter();
        graphPlotter(std::vector<T*> xData, std::vector<T*> yData);
        graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels);
        //graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> zData); //coming soon
        //graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> yData, std::vector<std::string> labels); //coming soon
        ~graphPlotter();

        void plot(std::vector<T*> xData, std::vector<T*> yData);
        void plot(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels);
        //void plot(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> zData); //coming soon
        //void plot(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> yData, std::vector<std::string> labels); //coming soon
        void setFigureSize(uint32_t xLength, uint32_t yLength);
        void setXdata();
        void setYdata();

        void xLim(T to, T from);
        void yLim(T to, T from);
        void xLabel(std::string label);
        void yLabel(std::string label);
        void showLegend(bool active);
        void showGrid(bool active);
        void showPlot(bool active);
        void title(std::string plotTitle);

    private:
        std::vector<T*> m_xData;
        std::vector<T*> m_yData;
        std::vector<std::string> m_labels;

};

template <class T> graphPlotter<T>::graphPlotter()
{
    // empty for now
}

template <class T> graphPlotter<T>::graphPlotter(std::vector<T*> xData, std::vector<T*> yData)
{
    if(xData.size() != yData.size())
    {
        std::cout<<__PRETTY_FUNCTION__<<": size of xData != size of yData"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": size of xData is "<<xData.size()<<" size of yData is"<<yData.size()<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<yData.size()<<std::endl;
        assert(false);
    }
    
    m_xData = xData;
    m_yData = yData;
}

#endif //GRAPH_PLOTTER_H