#include "alchemy/host_link/host.h"
#include "alchemy/hw/alchemy_lab.h"
#include "alchemy/led/panel.h"
#include "alchemy/surface/button_bank.h"
#include "alchemy/surface/control_loop.h"
#include "alchemy/surface/pager.h"
#include "alchemy/surface/presets.h"
#include "alchemy/surface/settings.h"
#include "alchemy/surface/virtual_button.h"
#include "alchemy/surface/virtual_knob.h"
#include "daisy_seed.h"
#include "manual.h"

const uint8_t page_count{3};

namespace palette {

using Rgb = alchemy::LedPanel::Rgb;

const Rgb light_orange = {0xe6, 0x9f, 0};
const Rgb green = {0, 0x9e, 0x73};
const Rgb gray = {0x60, 0x60, 0x60};
const Rgb pink = {0xcc, 0x79, 0xa7};

} // namespace palette

// API surfaces
alchemy::AlchemyLab hw;
alchemy::ControlLoop loop{hw};
alchemy::Pager pager{alchemy::Pager(page_count, alchemy::kNumPots)
                         .Cycle(hw.buttons[alchemy::kButtonB1])};
alchemy::ButtonBank buttons;
alchemy::Presets presets{hw.seed.qspi};
alchemy::Settings settings(hw, &pager);
alchemy::hostlink::Host host{presets, "example", "Example", "0.1.0",
                             "template"};

// Knobs
alchemy::VirtualKnob a1_knob = alchemy::VirtualKnob(alchemy::kPotTopLeft, "A1")
                                   .Linear(0.0, 1.0)
                                   .Ring(alchemy::Level(palette::light_orange))
                                   .Ident("a.1")
                                   .Help("A1 help");
alchemy::VirtualKnob b1_knob = alchemy::VirtualKnob(alchemy::kPotTopRight, "B1")
                                   .Linear(0.0, 1.0)
                                   .Ring(alchemy::Level(palette::light_orange))
                                   .Ident("b.1")
                                   .Help("B1 help");
alchemy::VirtualKnob c1_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleLeft, "C1")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Level(palette::light_orange))
        .Ident("c.1")
        .Help("C1 help");
alchemy::VirtualKnob d1_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleRight, "D1")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Level(palette::light_orange))
        .Ident("d.1")
        .Help("D1 help");
alchemy::VirtualKnob e1_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomLeft, "E1")
        .Exp(1.0, 1000.0)
        .Ring(alchemy::Level(palette::light_orange))
        .Ident("e.1")
        .Help("E1 help");
alchemy::VirtualKnob f1_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomRight, "F1")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Level(palette::light_orange))
        .Ident("f.1")
        .Help("F1 help");
alchemy::VirtualKnob a2_knob =
    alchemy::VirtualKnob(alchemy::kPotTopLeft, "A2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("a.2")
        .Help("A2 help");
alchemy::VirtualKnob b2_knob =
    alchemy::VirtualKnob(alchemy::kPotTopRight, "B2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("b.2")
        .Help("B2 help");
alchemy::VirtualKnob c2_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleLeft, "C2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("c.2")
        .Help("C2 help");
alchemy::VirtualKnob d2_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleRight, "D2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("d.2")
        .Help("D2 help");
alchemy::VirtualKnob e2_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomLeft, "E2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("e.2")
        .Help("E2 help");
alchemy::VirtualKnob f2_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomRight, "F2")
        .Linear(0.0, 1.0)
        .Ring(alchemy::Bipolar(palette::pink, palette::pink, palette::gray))
        .Ident("f.2")
        .Help("F2 help");
alchemy::VirtualKnob a3_knob =
    alchemy::VirtualKnob(alchemy::kPotTopLeft, "A3")
        .Linear(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("a.3")
        .Help("A3 help");
alchemy::VirtualKnob b3_knob =
    alchemy::VirtualKnob(alchemy::kPotTopRight, "B3")
        .Linear(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("b.3")
        .Help("B3 help");
alchemy::VirtualKnob c3_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleLeft, "C3")
        .Linear(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("c.3")
        .Help("C3 help");
alchemy::VirtualKnob d3_knob =
    alchemy::VirtualKnob(alchemy::kPotMiddleRight, "D3")
        .Linear(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("d.3")
        .Help("D3 help");
alchemy::VirtualKnob e3_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomLeft, "E3")
        .Exp(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("e.3")
        .Help("E3 help");
alchemy::VirtualKnob f3_knob =
    alchemy::VirtualKnob(alchemy::kPotBottomRight, "F3")
        .Linear(-1.0, 1.0)
        .Ring(alchemy::Bipolar(palette::green, palette::green, palette::gray))
        .Ident("f.3")
        .Help("F3 help");

// Buttons
alchemy::VirtualButton page_button =
    alchemy::VirtualButton(alchemy::kButtonB1, "Page")
        .Ident("page")
        .Role(alchemy::VirtualButton::Role::Modal)
        .Help("Page cycle")
        .Tap(alchemy::VirtualButton::Action::Cycle)
        .GestureHelp("tap",
                     "Cycles through the pages in the order of A, B, and C.");

// Pages
alchemy::Page a_page =
    alchemy::Page(0)
        .Name("A")
        .Color("#e69f00" /* light orange */)
        .Knobs(a1_knob, b1_knob, c1_knob, d1_knob, e1_knob, f1_knob)
        .Help("Page A help");
alchemy::Page b_page =
    alchemy::Page(1)
        .Name("B")
        .Color("#cc79a7" /* pink */)
        .Knobs(a2_knob, b2_knob, c2_knob, d2_knob, e2_knob, f2_knob)
        .Help("Page B help");
alchemy::Page c_page =
    alchemy::Page(2)
        .Name("C")
        .Color("#009e73" /* green */)
        .Knobs(a3_knob, b3_knob, c3_knob, d3_knob, e3_knob, f3_knob)
        .Help("Page C help");

void process_block(daisy::AudioHandle::InputBuffer in,
                   daisy::AudioHandle::OutputBuffer out, size_t n) {}

void update_params() {}

int main() {
  hw.Init();

  // Set up settings.
  settings.UseBrightness();
  settings.UsePresets(presets);

  settings.Page(0).Name("Global").Help("Global settings help");

  // Set up presets.
  presets.Manage(pager);
  presets.Manage(buttons);
  presets.Manage(settings);
  presets.UseNames();
  presets.Init();
  presets.BootLoad();

  // Grab initial parameter values.
  update_params();

  // Start processing audio.
  hw.StartAudio(process_block);

  // Bind surfaces to the control loop.
  loop.Use(pager)
      .Use(buttons)
      .Use(settings)
      .Use(host)
      .Use(a_page)
      .Use(b_page)
      .Use(c_page)
      .OnFrame(update_params);

  build_manual(host);

  // Start the control loop.
  for (;;) {
    loop.Tick();
  }
}
