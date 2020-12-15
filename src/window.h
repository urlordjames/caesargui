#include "wx/wx.h"
#include "wx/spinctrl.h"
#include "caesarify.h"

class fMain: public wxFrame {
public:
  fMain();
private:
  wxBoxSizer *row = nullptr;
  wxBoxSizer *column = nullptr;

  wxTextCtrl *text = nullptr;
  wxSpinCtrl *offset = nullptr;
  wxButton *button = nullptr;
  wxTextCtrl *output = nullptr;

  Caesar *caesar = new Caesar();

  void onButtonClick(wxCommandEvent &event);

  wxDECLARE_EVENT_TABLE();
};
