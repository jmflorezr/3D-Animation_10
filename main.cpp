#include "iostream"
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkNew.h>
#include <vtkPNGReader.h>
#include <vtkImageViewer2.h>
#include <vtkNamedColors.h>
#include <vtkImageAccumulate.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkWarpScalar.h>
#include <vtkLookupTable.h>

/* Include missing libraries
 * TODO !!!
 */

#define vtkSPtr vtkSmartPointer
#define vtkSPtrNew(Var, Type) vtkSPtr<Type> Var = vtkSPtr<Type>::New();

using namespace std;

int main()
{
    /* Read the image with the grey scale height
     * values */

    vtkSPtrNew(reader, vtkPNGReader);
    reader->SetFileName("../Img/Mountain.png");
    double* hi = 0;
    double* lo = 0;

   /* vtkSPtrNew(imageViewer, vtkImageViewer2);
    imageViewer->SetInputConnection(reader->GetOutputPort());
    vtkSPtrNew(renderWindowInteractor,vtkRenderWindowInteractor);


    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->GetRenderWindow()->SetWindowName("PNGReader");
    imageViewer->Render();

    renderWindowInteractor->Start();*/

    // TODO !!!


    // Save the lowest (lo) and highest (hi) values of the image in an variable 

    vtkSPtrNew(imageAccumulate, vtkImageAccumulate);
    imageAccumulate->SetInputConnection(reader->GetOutputPort());
    imageAccumulate->Update();
    hi = imageAccumulate->GetMax();
    lo = imageAccumulate->GetMin();
    std::cout<<"Highest value: "<<*hi<<endl;
    std::cout<<"Lowest value: "<<*lo<<endl;    

    
    // TODO !!!
    
    /* Extract geometry from the structured points'
     * dataset (Image)*/ 
    vtkSPtrNew( surface, vtkImageDataGeometryFilter );
    surface->SetInputConnection(reader->GetOutputPort());
    surface->Update();

    /* Deform geometry with scalar data
     * using the highest value saved before 
     */
    vtkSPtrNew( warpGemoetry , vtkWarpScalar );
    warpGemoetry->SetInputConnection(surface->GetOutputPort());
    warpGemoetry->SetScaleFactor(-0.009);
    
    // TODO!!!

    /* Map scalar (height) values into color (RGBA)
     */ 
    vtkSPtrNew( lut, vtkLookupTable);
    lut->SetRange(0,4);
    int mask_opacity = 1;
    lut->SetRampToLinear();
    lut->SetValueRange(0, 1);
    lut->SetHueRange(0, 0);
    lut->SetSaturationRange(0, 0);
    lut->SetNumberOfTableValues(40);
    lut->SetTableRange(0, 39);
    lut->SetTableValue(0, 0.149, 0.3059, 0.541, mask_opacity);//  BLUE
    lut->SetTableValue(1, 0.263, 0.149, 0, mask_opacity);
    lut->SetTableValue(2, 0.273, 0.159, 0, mask_opacity);
    lut->SetTableValue(3, 0.102, 0.6431, 0.043, mask_opacity);
    lut->SetTableValue(4, 0.092, 0.6331, 0.033, mask_opacity);
    lut->SetTableValue(5, 0.100, 0.5629, 0.045, mask_opacity);
    lut->SetTableValue(6, 0.090, 0.5529, 0.035, mask_opacity);
    lut->SetTableValue(7, 0.149, 0.5451, 0.106, mask_opacity);
    lut->SetTableValue(8, 0.139, 0.5451, 0.096, mask_opacity);
    lut->SetTableValue(9, 0.074, 0.5372, 0.023, mask_opacity);
    lut->SetTableValue(10, 0.086, 0.5294, 0.035, mask_opacity);
    lut->SetTableValue(11, 0.055, 0.3233, 0.023, mask_opacity);
    lut->SetTableValue(12, 0.065, 0.3333, 0.033, mask_opacity);
    lut->SetTableValue(13, 0.070, 0.3411, 0.039, mask_opacity);
    lut->SetTableValue(14, 0.080, 0.3511, 0.049, mask_opacity);
    lut->SetTableValue(15, 0.090, 0.3611, 0.059, mask_opacity);
    lut->SetTableValue(16, 0.100, 0.3711, 0.069, mask_opacity);
    lut->SetTableValue(17, 0.096, 0.3704, 0.064, mask_opacity);
    lut->SetTableValue(18, 0.106, 0.3804, 0.074, mask_opacity);
    lut->SetTableValue(19, 0.113, 0.4117, 0.078, mask_opacity);
    lut->SetTableValue(20, 0.123, 0.4217, 0.088, mask_opacity);
    lut->SetTableValue(21, 0.082, 0.4196, 0.043, mask_opacity);  
    lut->SetTableValue(22, 0.092, 0.4296, 0.053, mask_opacity);
    lut->SetTableValue(23, 0.102, 0.4396, 0.063, mask_opacity);
    lut->SetTableValue(24, 0.068, 0.4802, 0.021, mask_opacity);
    lut->SetTableValue(25, 0.078, 0.4902, 0.031, mask_opacity);    
    lut->SetTableValue(26, 0.076, 0.5076, 0.029, mask_opacity);
    lut->SetTableValue(27, 0.086, 0.5176, 0.039, mask_opacity);
    lut->SetTableValue(28, 0.089, 0.5251, 0.039, mask_opacity);
    lut->SetTableValue(29, 0.099, 0.5351, 0.049, mask_opacity);
    lut->SetTableValue(30, 0.109, 0.5451, 0.059, mask_opacity);
    lut->SetTableValue(31, 0.123, 0.707, 0.217, mask_opacity);
    lut->SetTableValue(32, 0.133, 0.717, 0.227, mask_opacity);
    lut->SetTableValue(33, 0.143, 0.727, 0.237, mask_opacity);
    lut->SetTableValue(34, 0.153, 0.737, 0.247, mask_opacity);
    lut->SetTableValue(35, 0.091, 0.758, 0.201, mask_opacity);
    lut->SetTableValue(36, 0.101, 0.768, 0.211, mask_opacity);
    lut->SetTableValue(37, 0.111, 0.778, 0.221, mask_opacity);
    lut->SetTableValue(38, 0.121, 0.788, 0.231, mask_opacity);
    lut->SetTableValue(39, 0.131, 0.798, 0.241, mask_opacity);
    // TODO !!


    /* Maps polygonal data to graphics primitives for later
     * GPU rendering
     */ 
    vtkSPtrNew( mapper, vtkPolyDataMapper );
    mapper->SetInputConnection( warpGemoetry->GetOutputPort() );
    mapper->ScalarVisibilityOn();
    mapper->SetScalarRange(*lo,*hi);
    mapper->SetLookupTable(lut);

    vtkSPtrNew( actor, vtkActor );
    actor->SetMapper( mapper );
    
    vtkSPtrNew(colors ,vtkNamedColors );
    actor->GetProperty()->SetSpecular(.3);
    actor->GetProperty()->SetSpecularPower(3);
    // Set representation to points 
    // TODO !!!

    vtkSPtrNew( renderer, vtkRenderer );
    renderer->AddActor(actor);
    renderer->SetBackground( 0.5, 0.6, 0.7 );

    vtkSPtrNew( renderWindow, vtkRenderWindow );
    renderWindow->AddRenderer( renderer );

    vtkSPtrNew( renderWindowInteractor, vtkRenderWindowInteractor );
    renderWindowInteractor->SetRenderWindow( renderWindow );

    renderer->ResetCamera();
    renderWindow->Render();
    renderWindowInteractor->Start();
    return 0;
}
