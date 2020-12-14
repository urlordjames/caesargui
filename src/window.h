#include "wx/wx.h"
#include "wx/spinctrl.h"
#include "caesarify.h"

class fMain: public wxFrame {
public:
  fMain();
private:
  wxBoxSizer *column = nullptr;

  wxTextCtrl *text = nullptr;
  wxSpinCtrl *offset = nullptr;
  wxButton *button = nullptr;

  Caesar *caesar = new Caesar();

  void onButtonClick(wxCommandEvent &event);

  wxDECLARE_EVENT_TABLE();
};
