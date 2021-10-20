#include "vtk-interface.hxx"

void plot(
  looney::math::function callback,
	std::array<double, 2> domain,
	std::array<double, 2> range
) {
  vtkNew<vtkNamedColors> colors;

  // Create a table with some points in it.
  vtkNew<vtkTable> table;

  vtkNew<vtkFloatArray> arrX;
  arrX->SetName("X Axis");
  table->AddColumn(arrX);

  vtkNew<vtkFloatArray> arrY;
  arrY->SetName("Y Axis");
  table->AddColumn(arrY);


  // Fill in the table with some example values.
  int numPoints = 10000;
  float inc = (domain[1] - domain[0]) / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
    table->SetValue(i, 0, i * inc + domain[0]);
    table->SetValue(i, 1,
      static_cast<looney::math::function_range::type>(
        callback(looney::math::function_domain::type(1, i * inc + domain[0]))
      ).at(0));
  }

  // Set up the view
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetWindowName("LinePlot");
  // view->GetRenderer()->SetBackground(colors->GetColor3d("SlateGray").GetData());

  // Add multiple line plots, setting the colors etc.
  vtkNew<vtkChartXY> chart;
  view->GetScene()->AddItem(chart);
	vtkPlot* line = chart->AddPlot(vtkChart::LINE);
	
	line->SetInputData(table, 0, 1);
	line->SetColor(0, 0, 0, 255);
	line->GetPen()->SetLineType(vtkPen::SOLID_LINE);
	line->SetWidth(1.1);
	line->GetYAxis()->SetRange(range[0], range[1]);
  // For dotted line, the line type can be from 2 to 5 for different dash/dot
  // patterns (see enum in vtkPen containing DASH_LINE, value 2):
  // #ifndef WIN32
  //   line->GetPen()->SetLineType(vtkPen::DASH_LINE);
  // #endif
  // (ifdef-ed out on Windows because DASH_LINE does not work on Windows
  //  machines with built-in Intel HD graphics card...)

	chart->SetPoint1(0,1);
	chart->SetPoint2(0,1);

  view->GetRenderWindow()->SetMultiSamples(0);

  // Start interactor
  view->GetRenderWindow()->Render();
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

};

void plot2d(const looney::math::function &_function) {
	std::array<double, 2> domain;
	std::array<double, 2> range;

	domain = std::get<1>(_function.m_domain.m_pack.at(0));
	range = std::get<1>(_function.m_range.m_pack.at(0));
	
	plot(_function, domain, range);
}