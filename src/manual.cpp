#include "manual.h"

#include "alchemy/surface/jack.h"
#include "alchemy/surface/manual.h"
#include "alchemy/surface/page.h"

extern alchemy::Page a_page, b_page, c_page;
extern alchemy::VirtualButton page_button;

alchemy::Jack in_l{alchemy::Jack("IN_L", "In L", alchemy::JackSig::AudioIn)
                       .Short("In L")
                       .Help("IN_L help")};
alchemy::Jack in_r{alchemy::Jack("IN_R", "In R", alchemy::JackSig::AudioIn)
                       .Short("In R")
                       .Help("IN_R help")};
alchemy::Jack cv_in_1{alchemy::Jack("J3", "CV In 1", alchemy::JackSig::CvBi)
                          .Short("CV 1")
                          .Help("CV 1 help")};
alchemy::Jack cv_in_2{alchemy::Jack("J4", "CV In 2", alchemy::JackSig::CvBi)
                          .Short("CV 2")
                          .Help("CV 2 help")};
alchemy::Jack cv_in_3{alchemy::Jack("J5", "CV In 3", alchemy::JackSig::CvBi)
                          .Short("CV 3")
                          .Help("CV 3 help")};
alchemy::Jack cv_in_4{alchemy::Jack("J6", "CV In 4", alchemy::JackSig::CvBi)
                          .Short("CV 4")
                          .Help("CV 4 help")};
alchemy::Jack cv_in_5{alchemy::Jack("J7", "CV In 5", alchemy::JackSig::CvBi)
                          .Short("CV 5")
                          .Help("CV 5 help")};
alchemy::Jack cv_in_6{alchemy::Jack("J8", "CV In 6", alchemy::JackSig::CvBi)
                          .Short("CV 6")
                          .Help("CV 6 help")};
alchemy::Jack l_out{alchemy::Jack("OUT_L", "Out L", alchemy::JackSig::AudioOut)
                        .Short("Out L")
                        .Help("OUT_L help")};
alchemy::Jack r_out{alchemy::Jack("OUT_R", "Out R", alchemy::JackSig::AudioOut)
                        .Short("Out R")
                        .Help("OUT_R help")};

alchemy::Manual manual{
    alchemy::Manual()
        .Tagline("Firmware that generates 'missing descriptor' error in the "
                 "web programmer.")
        .Preamble("Connecting an Alchemy Lab running this firmware to the web "
                  "programmer will result in an error that the firmware "
                  "doesn't publish a parameter descriptor.")};

void build_manual(alchemy::hostlink::Host &host) {
  host.Jacks(in_l, in_r, cv_in_1, cv_in_2, cv_in_3, cv_in_4, cv_in_5, cv_in_6,
             l_out, r_out)
      .Buttons(page_button)
      .Attach(manual);
}
