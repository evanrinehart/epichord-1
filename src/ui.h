// generated by Fast Light User Interface Designer (fluid) version 2.1000

#ifndef ui_h
#define ui_h
#include <fltk/Window.h>
#include <unistd.h>
#include <stdio.h>
#include "seq.h"
#include "trackmodule.h"
#include <fltk/Group.h>
#include "trackinfo.h"
#include <fltk/Button.h>
#include <fltk/ScrollGroup.h>
#include "arranger.h"
#include "timeline.h"
#include "pianoroll.h"
#include "eventedit.h"
#include "trackselect.h"
#include "sampleview.h"
#include "keyboard.h"
#include "saveload.h"
#include <fltk/ValueInput.h>
#include <fltk/ValueOutput.h>
#include <fltk/ThumbWheel.h>
#include <fltk/CheckButton.h>
#include <fltk/Choice.h>
#include <fltk/Item.h>
#include <fltk/TabGroup.h>
#include <fltk/Input.h>
#include <fltk/TextEditor.h>
#include <fltk/TextDisplay.h>
#include <fltk/Widget.h>

class UI  {
public:
  UI();
  fltk::Window *main_window;
private:
  inline void cb_main_window_i(fltk::Window*, void*);
  static void cb_main_window(fltk::Window*, void*);
public:
      fltk::Group *song_edit;
          TrackInfo *track_info;
private:
          inline void cb__i(fltk::Button*, void*);
          static void cb_(fltk::Button*, void*);
public:
          Timeline *song_timeline;
        fltk::ScrollGroup *song_scroll;
          Arranger *arranger;
      fltk::Group *pattern_edit;
            Timeline *pattern_timeline;
          fltk::ScrollGroup *pattern_scroll;
            PianoRoll *piano_roll;
            EventEdit *event_edit;
            TrackSelect *track_select;
            SampleView *sample_view;
            Keyboard *keyboard;
private:
          inline void cb_1_i(fltk::Button*, void*);
          static void cb_1(fltk::Button*, void*);
public:
      fltk::Button *play_button;
private:
      inline void cb_play_button_i(fltk::Button*, void*);
      static void cb_play_button(fltk::Button*, void*);
public:
      fltk::Button *stop_button;
private:
      inline void cb_stop_button_i(fltk::Button*, void*);
      static void cb_stop_button(fltk::Button*, void*);
public:
      fltk::Button *record_button;
private:
      inline void cb_record_button_i(fltk::Button*, void*);
      static void cb_record_button(fltk::Button*, void*);
public:
      fltk::Button *loop_toggle;
private:
      inline void cb_loop_toggle_i(fltk::Button*, void*);
      static void cb_loop_toggle(fltk::Button*, void*);
public:
      fltk::Button *keyboard_toggle;
      fltk::Button *config_button;
private:
      inline void cb_config_button_i(fltk::Button*, void*);
      static void cb_config_button(fltk::Button*, void*);
public:
      fltk::Button *file_button;
private:
      inline void cb_file_button_i(fltk::Button*, void*);
      static void cb_file_button(fltk::Button*, void*);
public:
      fltk::Button *help_button;
private:
      inline void cb_help_button_i(fltk::Button*, void*);
      static void cb_help_button(fltk::Button*, void*);
public:
        fltk::Button *qbutton4;
private:
        inline void cb_qbutton4_i(fltk::Button*, void*);
        static void cb_qbutton4(fltk::Button*, void*);
public:
        fltk::Button *qbutton8;
private:
        inline void cb_qbutton8_i(fltk::Button*, void*);
        static void cb_qbutton8(fltk::Button*, void*);
public:
        fltk::Button *qbutton16;
private:
        inline void cb_qbutton16_i(fltk::Button*, void*);
        static void cb_qbutton16(fltk::Button*, void*);
public:
        fltk::Button *qbutton32;
private:
        inline void cb_qbutton32_i(fltk::Button*, void*);
        static void cb_qbutton32(fltk::Button*, void*);
public:
        fltk::Button *qbutton64;
private:
        inline void cb_qbutton64_i(fltk::Button*, void*);
        static void cb_qbutton64(fltk::Button*, void*);
public:
        fltk::Button *qbutton128;
private:
        inline void cb_qbutton128_i(fltk::Button*, void*);
        static void cb_qbutton128(fltk::Button*, void*);
public:
        fltk::Button *qbutton0;
private:
        inline void cb_qbutton0_i(fltk::Button*, void*);
        static void cb_qbutton0(fltk::Button*, void*);
public:
  fltk::Window *config_window;
    fltk::ValueOutput *bpm_output;
    fltk::ThumbWheel *bpm_wheel;
private:
    inline void cb_bpm_wheel_i(fltk::ThumbWheel*, void*);
    static void cb_bpm_wheel(fltk::ThumbWheel*, void*);
public:
  fltk::Window *help_window;
        fltk::Input *title_text;
        fltk::Input *author_text;
        fltk::TextEditor *info_text;
  fltk::Window *action_window;
private:
    inline void cb_new_i(fltk::Button*, void*);
    static void cb_new(fltk::Button*, void*);
    inline void cb_save_i(fltk::Button*, void*);
    static void cb_save(fltk::Button*, void*);
    inline void cb_save1_i(fltk::Button*, void*);
    static void cb_save1(fltk::Button*, void*);
    inline void cb_load_i(fltk::Button*, void*);
    static void cb_load(fltk::Button*, void*);
    inline void cb_export_i(fltk::Button*, void*);
    static void cb_export(fltk::Button*, void*);
public:
  fltk::Window *key_config;
};
#endif
