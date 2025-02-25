// ui_popup_files.h - Johan Smet - BSD-3-Clause (see LICENSE)
//
// file related popups

#ifndef LSIM_GUI_UI_POPUP_FILES_H
#define LSIM_GUI_UI_POPUP_FILES_H

#include <string>
#include <functional>

namespace lsim {

class LSimContext;

namespace gui {

using on_select_func_t = std::function<void (const std::string &)>;

void ui_file_selector_open(LSimContext *context, on_select_func_t on_select);
void ui_file_selector_define();

void ui_filename_entry_open(on_select_func_t on_close);
void ui_filename_entry_define();

} // namespace lsim::gui

} // namespace lsim



#endif // LSIM_GUI_UI_POPUP_FILES_H