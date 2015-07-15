#include "ScatterCtrl_Demo.h"


void TabBallPlot::Init()
{
	CtrlLayout(*this);	
	SizePos();
	
	scatter.SetMouseHandling(true, true).ShowContextMenu();

	for (double size = 0; size <= 10; size += 2.) {
		Vector<double> &data = s1.Add();
		data << size << 10 + 50*sin(size/M_PI) << size*4 + 4; 		
	}
	idsBall << 2;
	static Vector<int> idVoid;
	scatter.AddSeries(s1, 1, 0, idVoid, idVoid, idsBall).Legend("Importance").MarkStyle<BallPlot>()
		   .NoPlot().MarkColor(Green()).MarkBorderColor(LtRed()).MarkBorderWidth(3);
	
	scatter.SetLabelY("Size");
	scatter.FitToData(true, 0.2);
}

ScatterDemo *Construct16()
{
	static TabBallPlot tab;
	return &tab;
}

INITBLOCK {
	RegisterExample("BallPlot", Construct16, __FILE__);
}