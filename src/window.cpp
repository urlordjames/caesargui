#include "window.h"

wxBEGIN_EVENT_TABLE(fMain, wxFrame)
  EVT_BUTTON(1, fMain::onButtonClick)
wxEND_EVENT_TABLE()

fMain::fMain(): wxFrame(nullptr, wxID_ANY, "ceasargui") {
  column = new wxBoxSizer(wxVERTICAL);
  text = new wxTextCtrl(this, wxID_ANY, "lorem ipsum", wxDefaultPosition, wxSize(100, 30), wxTE_MULTILINE);
  offset = new wxSpinCtrl(this, wxID_ANY, "offset", wxDefaultPosition, wxSize(50, 50), wxSP_ARROW_KEYS, 0, 25, 3, "dog");
  button = new wxButton(this, 1, "encrypt", wxDefaultPosition, wxSize(100, 30));

  column->Add(text, 1, wxEXPAND | wxALL, 10);
  column->Add(offset, 1, wxEXPAND | wxALL, 10);
  column->Add(button, 1, wxEXPAND | wxALL, 10);

  SetSizerAndFit(column);
}

void fMain::onButtonClick(wxCommandEvent &event) {
  std::string input = text->GetValue().ToStdString();
  int shiftamt = offset->GetValue();
  wxMessageBox(caesar->caesarify(&input, shiftamt));
  event.Skip();
}
