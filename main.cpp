#include <windows.h>
#include <iostream>

using namespace std;

void changeResolution(int width, int height, int refreshRate)
{
  DEVMODE dm = {0};
  dm.dmSize = sizeof(dm);
  dm.dmPelsWidth = width;
  dm.dmPelsHeight = height;
  dm.dmDisplayFrequency = refreshRate;
  dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

  if (ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY) != DISP_CHANGE_SUCCESSFUL)
  {
    cout << "Falha ao alterar a resolução!" << endl;
  }
  else
  {
    cout << "Resolução alterada com sucesso para " << width << "x" << height << " @" << refreshRate << "Hz" << endl;
  }
}

int main()
{
  int choice;

  cout << "Selecione a resolucao desejada:" << endl;
  cout << "1 - 800x600 @144Hz" << endl;
  cout << "2 - 1280x1024 @144Hz" << endl;
  cout << "3 - 1920x1080 @144Hz" << endl;
  cout << "Opcao: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    changeResolution(800, 600, 144);
    break;
  case 2:
    changeResolution(1280, 1024, 144);
    break;
  case 3:
    changeResolution(1920, 1080, 144);
    break;
  default:
    cout << "Opcao invalida!" << endl;
  }

  system("pause");
  return 0;
}