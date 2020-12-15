#include "window.h"

wxBEGIN_EVENT_TABLE(fMain, wxFrame)
  EVT_BUTTON(1, fMain::onButtonClick)
wxEND_EVENT_TABLE()

fMain::fMain(): wxFrame(nullptr, wxID_ANY, "ceasargui") {
  row = new wxBoxSizer(wxHORIZONTAL);
  column = new wxBoxSizer(wxVERTICAL);

  text = new wxTextCtrl(this, wxID_ANY, "lorem ipsum", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
  offset = new wxSpinCtrl(this, wxID_ANY, "offset", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 25, 3, "dog");
  button = new wxButton(this, 1, "encrypt", wxDefaultPosition, wxDefaultSize);
  output = new wxTextCtrl(this, wxID_ANY, "output", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

  row->Add(column, 1, wxEXPAND | wxALL, 10);
  row->Add(output, 1, wxEXPAND | wxALL, 10);

  column->Add(text, 1, wxEXPAND | wxALL, 10);
  column->Add(offset, 1, wxEXPAND | wxALL, 10);
  column->Add(button, 1, wxEXPAND | wxALL, 10);

  SetSizerAndFit(row);
}

void fMain::onButtonClick(wxCommandEvent &event) {
  std::string input = text->GetValue().ToStdString();
  int shiftamt = offset->GetValue();
  output->SetValue(caesar->caesarify(&input, shiftamt));
  event.Skip();
}
