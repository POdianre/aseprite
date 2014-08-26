// Aseprite UI Library
// Copyright (C) 2001-2013  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef UI_SYSTEM_H_INCLUDED
#define UI_SYSTEM_H_INCLUDED
#pragma once

#include "gfx/fwd.h"
#include "ui/base.h"
#include "ui/cursor_type.h"
#include "ui/mouse_buttons.h"

struct BITMAP;

#define JI_SCREEN_W ui::ji_screen_w
#define JI_SCREEN_H ui::ji_screen_h

namespace she { class Display; }

namespace ui {

  class Widget;

  // Screen related

  extern struct BITMAP* ji_screen;
  extern int ji_screen_w;
  extern int ji_screen_h;

  // Simple flag to indicate that something in the screen was modified
  // so a flip to the real screen is needed.
  extern bool dirty_display_flag;

  void set_display(she::Display* display);

  // Timer related

  extern int volatile ji_clock;   /* in milliseconds */

  // Mouse related

  // Updates the position of the mouse cursor overlay depending on the
  // current mouse position.
  void UpdateCursorOverlay();

  void set_use_native_cursors(bool state);
  CursorType jmouse_get_cursor();
  void jmouse_set_cursor(CursorType type);

  void jmouse_hide();
  void jmouse_show();

  bool jmouse_is_hidden();
  bool jmouse_is_shown();

  bool _internal_poll_mouse();

  void _internal_no_mouse_position();
  void _internal_set_mouse_position(const gfx::Point& newPos);
  void _internal_set_mouse_buttons(MouseButtons buttons);

  gfx::Point get_mouse_position();

  MouseButtons jmouse_b(int antique);
  int jmouse_x(int antique);
  int jmouse_y(int antique);
  int jmouse_z(int antique);

} // namespace ui

#endif
