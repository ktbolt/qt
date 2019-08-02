
#include <iostream>

#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDataArray.h>
#include <vtkIdList.h>
#include <vtkSmartPointer.h>
#include <vtkUnsignedCharArray.h>
#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridReader.h>

void read_vtu_file(std::string file_name)
{
  vtkSmartPointer<vtkXMLUnstructuredGridReader> reader = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader->SetFileName(file_name.c_str());
  reader->Update();

  vtkUnstructuredGrid* ugrid = reader->GetOutput();

  /*
  vtkUnsignedCharArray* cell_types = ugrid->GetCellTypesArray();
  unsigned char* ptr = cell_types->GetPointer(0);
  for (int i = 0; i < num_cells; i++) { 
      int tmp = static_cast<unsigned char>(ugrid->GetCellType(i));
      std::cout << "[read_vtu_file] Cell type '" << tmp << "'" << std::endl;
      //std::cout << "[read_vtu_file] Cell type " << ptr[i] << std::endl;
  }
  */

  auto points = ugrid->GetPoints();
  auto num_points = points->GetNumberOfPoints();
  std::cout << "[read_vtu_file] Number of points " << num_points << std::endl;
  /*
  double point[3];
  for (int i = 0; i < num_points; i++) {
      points->GetPoint(i, point);
      std::cout << "[read_vtu_file] point "; 
      std::cout << " " << point[0];
      std::cout << " " << point[1];
      std::cout << " " << point[2] << std::endl;
  }
  */

  auto num_cells = ugrid->GetNumberOfCells();
  vtkCellArray* cells = ugrid->GetCells();
  std::cout << "[read_vtu_file] Number of cells " << num_cells << std::endl;
  
  /*
  for (int i = 0; i < num_cells; i++) {
      vtkSmartPointer<vtkIdList> ids = vtkSmartPointer<vtkIdList>::New();
      ugrid->GetCellPoints(i, ids);
      std::cout << "[read_vtu_file] Cell " << i << " "; 
      for(vtkIdType j = 0; j < ids->GetNumberOfIds(); j++) {
          auto id = ids->GetId(j);
          std::cout << " " << id;
      }
      std::cout << std::endl;
  }
  */


}
