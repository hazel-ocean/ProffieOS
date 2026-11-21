#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define IDLE_OFF_TIME 30000
#define SA22C_TWIST_OFF
#define SA22C_TWIST_ON
#define SA22C_STAB_ON
#define FEMALE_TALKIE_VOICE
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sa22c_buttons.h"

// ProffieOS.ino includes CONFIG_PROP twice.
#ifndef KR_GRAFLEX_BUTTONS_H
#define KR_GRAFLEX_BUTTONS_H
class KRGraflexButtons : public SaberSA22CButtons {
public:
  const char* name() override { return "KRGraflexButtons"; }

  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
      // A saved click waits out the double-click window, so a double click
      // still triggers Force without a clash.
      case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
        if (SaberBase::Lockup()) return false;
        SaberBase::DoClash();
        return true;
    }
    return SaberSA22CButtons::Event2(button, event, modifiers);
  }
};
#endif

#undef PROP_TYPE
#define PROP_TYPE KRGraflexButtons
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {


	//OG Trilogy

	{ "Luke_ANH_Training;common", "tracks/Luke_ANH.wav",
	StylePtr<Layers<
  Layers<
    RandomPerLEDFlicker<Rgb<110,225,255>,Rgb<55,113,128>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<73,150,191>>>>,
  LockupTrL<Layers<AlphaL<Blinking<LemonChiffon,Strobe<Rgb<239,182,43>,Moccasin,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,Moccasin,50>,BrownNoiseFlicker<LemonChiffon,Rgb<239,182,43>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14599>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Moccasin,Rgb<239,182,43>,500>,White,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Azure,Bump<Int<12000>,Int<18000>>>,TrFade<500>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LemonChiffon,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<OrangeRed>,
  ResponsiveBlastWaveL<Sparkle<OrangeRed,White,9999,399>,Int<500>,Scale<SwingSpeed<200>,Int<200>,Int<200>>,Int<999>,Int<25000>>,
  TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Sparkle<Rgb<212,175,55>,Rgb<180,130,0>>,Sparkle<Rgb<212,175,55>>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<27000>,Int<5000>>>,TrWipeIn<600>,TrFade<600>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<250>,TrWipeIn<1200>>>>(),

		//Ice Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<110,225,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Luke - ANH Training"},

	{ "Luke_ANH_Graflex;common", "tracks/Luke_ANH.wav",
	StylePtr<Layers<
  Layers<
    RandomPerLEDFlicker<Rgb<110,225,255>,Rgb<55,113,128>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<73,150,191>>>>,
  LockupTrL<Layers<AlphaL<Blinking<LemonChiffon,Strobe<Rgb<239,182,43>,Moccasin,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,Moccasin,50>,BrownNoiseFlicker<LemonChiffon,Rgb<239,182,43>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14599>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Moccasin,Rgb<239,182,43>,500>,White,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Azure,Bump<Int<12000>,Int<18000>>>,TrFade<500>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LemonChiffon,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<OrangeRed>,
  ResponsiveBlastWaveL<Sparkle<OrangeRed,White,9999,399>,Int<500>,Scale<SwingSpeed<200>,Int<200>,Int<200>>,Int<999>,Int<25000>>,
  TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Sparkle<Rgb<212,175,55>,Rgb<180,130,0>>,Sparkle<Rgb<212,175,55>>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<27000>,Int<5000>>>,TrWipeIn<600>,TrFade<600>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<250>,TrWipeIn<1200>>>>(),

		//Ice Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<110,225,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<110,225,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Luke - ANH Graflex"},

	{ "Vader_ANH;common", "tracks/Vader_ANH.wav",
    	StylePtr<Layers<
      AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
      TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrDelay<4999>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<800>>,EFFECT_FORCE>,
      EffectSequence<EFFECT_FORCE,AlphaL<AudioFlickerL<RotateColorsX<Variation,Red>>,SwingSpeed<300>>,AlphaL<White,Int<0>>>,

      //VaderOWK_ANH_Lockup
      LockupTrL<Layers<
        AlphaL<Blinking<Yellow,Strobe<Yellow,LemonChiffon,30,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        AlphaL<Blinking<BrownNoiseFlicker<Yellow,LemonChiffon,50>,BrownNoiseFlicker<Yellow,Yellow,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<LemonChiffon,Strobe<BrownNoiseFlicker<LemonChiffon,LemonChiffon,500>,Yellow,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,LemonChiffon,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LemonChiffon,Int<20000>>,Yellow,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,LemonChiffon,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<Yellow,Yellow,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Yellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<200>>>,EFFECT_LOCKUP_END>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
      //AlphaL<RotateColorsX<Variation,Rgb<25,0,0>>,Bump<Int<0>,Int<8000>>>,
      ResponsiveStabL<Orange>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Yellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,GreenYellow,20,20>,BrownNoiseFlicker<Yellow,Rgb<108,192,6>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,LightYellow,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<850>,TrWipeIn<1060>>>>(),
     	StylePtr<Layers<
       AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
       TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrDelay<4999>,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<800>>,EFFECT_FORCE>,
       EffectSequence<EFFECT_FORCE,AlphaL<AudioFlickerL<RotateColorsX<Variation,Red>>,SwingSpeed<300>>,AlphaL<White,Int<0>>>,

       //VaderOWK_ANH_Lockup
       LockupTrL<Layers<
         AlphaL<Blinking<Yellow,Strobe<Yellow,LemonChiffon,30,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
         AlphaL<Blinking<BrownNoiseFlicker<Yellow,LemonChiffon,50>,BrownNoiseFlicker<Yellow,Yellow,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<LemonChiffon,Strobe<BrownNoiseFlicker<LemonChiffon,LemonChiffon,500>,Yellow,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
       TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,LemonChiffon,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
       TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LemonChiffon,Int<20000>>,Yellow,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
       TransitionEffectL<TrConcat<TrInstant,LemonChiffon,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
       TransitionEffectL<TrConcat<TrInstant,Strobe<Yellow,Yellow,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Yellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<200>>>,EFFECT_LOCKUP_END>,
       LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
       AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
       //AlphaL<RotateColorsX<Variation,Rgb<25,0,0>>,Bump<Int<0>,Int<8000>>>,
       ResponsiveStabL<Orange>,
       EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
       TransitionEffectL<TrConcat<TrInstant,Yellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,GreenYellow,20,20>,BrownNoiseFlicker<Yellow,Rgb<108,192,6>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,LightYellow,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
       LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
       LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
       InOutTrL<TrWipe<850>,TrWipeIn<1060>>>>(),
	"Vader - ANH"},

	{ "Luke_ESB;common", "tracks/Luke_ESB.wav",
	StylePtr<Layers<
  HumpFlicker<Rgb<55,155,255>,Rgb<28,78,128>,7>,
  LockupTrL<Layers<
    AlphaL<Blinking<Moccasin,Strobe<NavajoWhite,Rgb<255,147,50>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
    AlphaL<Blinking<BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,50>,BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Moccasin,Rgb<255,197,100>,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Moccasin,Rgb<255,197,100>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<PeachPuff,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,PeachPuff,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<100,100,150>,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<PeachPuff,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<Azure,Bump<Int<12000>,Int<18000>>>,TrFade<500>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LemonChiffon,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  ResponsiveStabL<OrangeRed>,
  ResponsiveBlastWaveL<Sparkle<OrangeRed,White,9999,399>,Int<500>,Scale<SwingSpeed<200>,Int<200>,Int<200>>,Int<999>,Int<25000>>,
  TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,Cornsilk,20,20>,BrownNoiseFlicker<LemonChiffon,Cornsilk,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<250>,TrWipeIn<1100>>>>(),
		//Light Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<55,155,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<55,155,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Luke"},

	{ "Vader_ESB;common", "tracks/Vader_ESB.wav",
    	StylePtr<Layers<
      Layers<
        RotateColorsX<Variation,Red>,
        RandomL<RotateColorsX<Variation,Rgb<128,0,0>>>,
        RandomL<RotateColorsX<Variation,Rgb<64,0,0>>>>,
      LockupTrL<Layers<
        AlphaL<Blinking<White,Strobe<White,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,White,50>,BrownNoiseFlicker<LemonChiffon,White,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14999>>>>,TrConcat<TrInstant,AlphaL<Blinking<LightYellow,Strobe<BrownNoiseFlicker<LemonChiffon,White,500>,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,White,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LightYellow,Int<20000>>,White,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,LightYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<White,LemonChiffon,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<LightYellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
      ResponsiveStabL<Orange>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<1000>,TrWipeIn<1060>>>>(),
    	StylePtr<Layers<
      Layers<
        RotateColorsX<Variation,Red>,
        RandomL<RotateColorsX<Variation,Rgb<128,0,0>>>,
        RandomL<RotateColorsX<Variation,Rgb<64,0,0>>>>,
      LockupTrL<Layers<
        AlphaL<Blinking<White,Strobe<White,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        AlphaL<Blinking<BrownNoiseFlicker<LemonChiffon,White,50>,BrownNoiseFlicker<LemonChiffon,White,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14999>>>>,TrConcat<TrInstant,AlphaL<Blinking<LightYellow,Strobe<BrownNoiseFlicker<LemonChiffon,White,500>,LemonChiffon,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<LemonChiffon,White,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<LightYellow,Int<20000>>,White,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,LightYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<White,LemonChiffon,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<LightYellow,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
      LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<6000>>,Int<-6000>>>,
      ResponsiveStabL<Orange>,
      EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
      TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
      LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
      LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<1000>,TrWipeIn<1060>>>>(),
	"Vader - ESB"},

	{ "Luke_RoTJ;common", "tracks/Luke_RoTJ.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Green CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,255,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"ROTJ"},

	{ "Vader_RoTJ;common", "tracks/Vader_RoTJ.wav",
    	StylePtr<Layers<HumpFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<100,0,0>>,50>,
    	LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>,AlphaL<LemonChiffon,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Sin<Int<10>,Int<10000>,Int<20000>>>>,SaberBase::LOCKUP_NORMAL>,
    	LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
    	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
    	TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    	TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,OrangeRed>>,TrFade<1200>>,EFFECT_IGNITION>,
    	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    	InOutTrL<TrWipe<450>,TrWipeIn<1000>,Black>>>(),
    	StylePtr<Layers<HumpFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<100,0,0>>,50>,
    	LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>,AlphaL<LemonChiffon,Bump<Sin<Int<10>,Int<10000>,Int<20000>>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Sin<Int<10>,Int<10000>,Int<20000>>>>,SaberBase::LOCKUP_NORMAL>,
    	LockupTrL<AlphaL<White,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
    	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<LemonChiffon,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>>,
    	TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    	TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,OrangeRed>>,TrFade<1200>>,EFFECT_IGNITION>,
    	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    	InOutTrL<TrWipe<450>,TrWipeIn<1000>,Black>>>(),
   	"Vader - ROTJ"},

	{ "Vader_R1;common", "tracks/Vader_R1.wav",
    	StylePtr<Layers<RotateColorsX<Variation,Rgb<120,0,0>>,
         AlphaL<RotateColorsX<Variation,Red>,SwingSpeed<100>>,
         LockupTrL<Layers<
            AlphaL<Blinking<Rgb<200,200,250>,Strobe<Black,Coral,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
            AlphaL<Blinking<BrownNoiseFlicker<Rgb<200,200,250>,Coral,50>,BrownNoiseFlicker<Moccasin,Black,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<OrangeRed,Rgb<255,100,100>,500>,Rgb<255,100,100>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
          TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<200,200,250>,Rgb<255,100,100>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Black,Int<20000>>,Rgb<255,100,100>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,Rgb<200,200,250>,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<200,200,250>,OrangeRed,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Rgb<255,100,100>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
         ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
         EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<NavajoWhite,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Moccasin,Rgb<243,182,39>,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<Orange,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<PapayaWhip,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<OrangeRed,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<White,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>,
         TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
         LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>,Stripes<2000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
         LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,Yellow,OrangeRed,Rgb<50,50,0>,Orange>,Stripes<2000,3000,LemonChiffon,Orange,Tomato,Coral>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
         InOutTrL<TrWipe<650>,TrWipeIn<650>,Black>>>(),
         StylePtr<Layers<RotateColorsX<Variation,Rgb<120,0,0>>,
         AlphaL<RotateColorsX<Variation,Red>,SwingSpeed<100>>,
         LockupTrL<Layers<
            AlphaL<Blinking<Rgb<200,200,250>,Strobe<Black,Coral,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
            AlphaL<Blinking<BrownNoiseFlicker<Rgb<200,200,250>,Coral,50>,BrownNoiseFlicker<Moccasin,Black,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<OrangeRed,Rgb<255,100,100>,500>,Rgb<255,100,100>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<300>,SaberBase::LOCKUP_NORMAL>,
          TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<200,200,250>,Rgb<255,100,100>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Black,Int<20000>>,Rgb<255,100,100>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,Rgb<200,200,250>,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
          TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<200,200,250>,OrangeRed,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Rgb<255,100,100>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
         ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
         EffectSequence<EFFECT_BLAST,ResponsiveBlastL<TransitionEffect<NavajoWhite,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,Layers<ResponsiveBlastFadeL<TransitionEffect<Moccasin,Rgb<243,182,39>,TrInstant,TrFade<100>,EFFECT_BLAST>,Scale<SwingSpeed<200>,Int<10000>,Int<18000>>>,ResponsiveBlastFadeL<Orange,Scale<SwingSpeed<200>,Int<4000>,Int<10000>>>>,BlastL<TransitionEffect<PapayaWhip,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>,ResponsiveBlastL<TransitionEffect<OrangeRed,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>>,BlastL<TransitionEffect<White,Rgb<243,182,39>,TrInstant,TrFade<50>,EFFECT_BLAST>>,
         TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<NavajoWhite,Moccasin,20,20>,BrownNoiseFlicker<NavajoWhite,Moccasin,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
         LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>,Stripes<2000,3000,White,Rgb<30,30,30>,White,Rgb<30,30,30>>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
         LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,Yellow,OrangeRed,Rgb<50,50,0>,Orange>,Stripes<2000,3000,LemonChiffon,Orange,Tomato,Coral>>,SmoothStep<Scale<TwistAngle<>,Int<29000>,Int<26000>>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
         InOutTrL<TrWipe<650>,TrWipeIn<650>,Black>>>(),
	"Vader - R1"},


	//Prequels

	{ "Obi-Wan - TPM;common", "tracks/TPM.wav",    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Button Light

	/* copyright Fett263 Rotoscope (Accent LED / PCB) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
OS6.7 v4.021
Single Style
Base Style: Hyper Responsive Rotoscope (Original Trilogy)


Base Color: Rgb<0,0,255> (0)

--Effects Included--
Ignition Effect: Instant
Retraction Effect: Instant
*/
StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrInstant>>>(),},

	{ "Qui-Gon - TPM;common", "tracks/TPM.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

				//Button Light

		/* copyright Fett263 Rotoscope (Accent LED / PCB) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,255,0> (0)

	--Effects Included--
	Ignition Effect: Instant
	Retraction Effect: Instant
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,InOutTrL<TrInstant,TrInstant>>>(),},

	{ "Maul;common", "tracks/TPM.wav",    StylePtr<Layers<Stripes<16000,-1000,RotateColorsX<Variation,Rgb16<47835,0,0>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,4975,4975>>,RotateColorsX<Variation,Rgb16<47835,0,0>>,800>,RotateColorsX<Variation,Rgb16<47835,0,0>>>,TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<30000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

				//Button Light

		/* copyright Fett263 Rotoscope (Accent LED / PCB) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<47835,0,0> (0)

	--Effects Included--
	Ignition Effect: Instant
	Retraction Effect: Instant
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,InOutTrL<TrInstant,TrInstant>>>(),},



	{ "Obi-Wan - AOTC;common", "tracks/Anakin_AOTC.wav",    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Obi-Wan"},


	{ "Anakin - AOTC;common", "tracks/Anakin_AOTC.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Anakin"},


	{ "Dooku - AOTC;common", "tracks/Dooku.wav",    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Dooku"},


	{ "Obi-Wan - ROTS;common", "tracks/ROTS.wav",    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Obi-Wan"},


	{ "Anakin - ROTS;common", "tracks/Anakin_ROTS.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Youngling Slayer"},


	{ "Palpatine;common", "tracks/Palpatine.wav",    StylePtr<Layers<Stripes<16000,-1000,RotateColorsX<Variation,Rgb16<47835,0,0>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,4975,4975>>,RotateColorsX<Variation,Rgb16<47835,0,0>>,800>,RotateColorsX<Variation,Rgb16<47835,0,0>>>,TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<30000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<47835,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb16<47835,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Palpatine"},


	{ "Yoda - ROTS;common", "tracks/Yoda.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Green CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,255,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Yoda"},


	{ "Mace - ROTS;common", "tracks/ROTS.wav",
	StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb16<14386,0,65535>>,RotateColorsX<Variation,Rgb16<8729,0,40112>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Purple CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<14386,0,65535> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Mace"},




	{ "Dooku - ROTS;common", "tracks/Dooku.wav",    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Dooku"},





   //Sequels

	{ "Kylo;common", "tracks/Kylo.wav",    StylePtr<Layers<Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Red>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<300>>,EFFECT_PREON>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Kylo"},

	{ "Rey;common", "tracks/Rey.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<4000>>>,TrFade<300>,AlphaL<DodgerBlue,Bump<Int<0>,Int<4000>>>,TrFade<300>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<4000>>>,TrDelay<350>>,EFFECT_PREON>>>(),

		//Yellow CC


	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<180,130,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Rey"},








	//TV Shows



		//Mando

	{ "Dark Saber;common", "tracks/Darksaber.wav",    StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb16<21919,21919,50739>>,RotateColorsX<Variation,Rgb16<20693,20693,49761>>>,Stripes<5000,-300,RotateColorsX<Variation,Rgb16<148,681,2521>>,RotateColorsX<Variation,Rgb16<148,681,2521>>,RotateColorsX<Variation,Rgb<10,10,20>>,RotateColorsX<Variation,Rgb<50,50,75>>>,300>,RotateColorsX<Variation,Rgb<35,35,75>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LightCyan,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<LightCyan,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LightCyan,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<SteelBlue>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<SteelBlue,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,SteelBlue,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Blue White CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<21919,21919,50739> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>>,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>>,RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb16<21919,21919,50739>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Mando"},




		//Ahsoka



	{ "Shin Hati;common", "tracks/Ahsoka_2.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb16<65535,10936,1442>>,RotateColorsX<Variation,Rgb16<49761,4182,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//OrangeRed CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<65535,10936,1442> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>>,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>>,RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb16<65535,10936,1442>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Shin Hati"},


	{ "Marrok;common", "tracks/Ahsoka_2.wav",    StylePtr<Layers<Mix<SwingSpeed<100>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,TransitionEffectL<TrConcat<TrInstant,White,TrFade<800>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<RotateColorsX<Variation,OrangeRed>,Bump<Int<0>,Int<8000>>>,ResponsiveStabL<Orange>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<200>,Int<8000>,Int<16000>>>,ResponsiveBlastWaveL<White,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<500>,TrWipeIn<800>>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Marrok"},


	{ "Ahsoka - White Sabers;common", "tracks/Ahsoka.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<White,Bump<Int<0>,Int<8000>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Silver White CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<100,100,150> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Ahsoka"},


		//CW

	{ "Ahsoka - CW;common", "tracks/CW.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Green CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,255,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Snips"},





		//Rebels

	{ "Ezra - Rebels (Blue);common", "tracks/Ezra.wav",
	StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,DodgerBlue>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Light Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,135,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Ezra"},

	{ "Ezra - Rebels (Green);common", "tracks/Ezra.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Green CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,255,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Ezra"},


	{ "Kanan - Rebels;common", "tracks/Kanan.wav",
	StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Kanan"},




	//BB

	{ "Asajj Ventress - BB (Yellow);common", "tracks/Asajj.wav",    StylePtr<Layers<HumpFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<120,120,0>>,50>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<RotateColorsX<Variation,Rgb<250,250,0>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<100>,Int<4000>>,Int<-4000>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

		//Yellow CC


	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<180,180,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<180,180,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Asajj"},



   //Legends


   { "Arcann;common", "tracks/Arcann.wav",    StylePtr<Layers<StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb16<40112,40112,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb16<25487,25487,0>>,RotateColorsX<Variation,Rgb16<40112,40112,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb16<57353,57353,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb16<37562,37562,0>>,RotateColorsX<Variation,Rgb16<49761,49761,0>>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),
		//Yellow CC


	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,255,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
   "Arcann"},


   { "Malak;common", "tracks/Malak.wav",    StylePtr<Layers<StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<30,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Red>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Rgb<80,0,0>>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

	   //Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
   "Malak"},

   { "Malgus;common", "tracks/Malgus.wav",    StylePtr<Layers<StripesX<Int<5000>,Int<-1400>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<30,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Red>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Rgb<80,0,0>>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

	   //Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
   "Malgus"},

   { "Mara (Darkside);common", "tracks/Mara.wav",    StylePtr<Layers<StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<10,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>,300>,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<Black,RotateColorsX<Variation,Rgb<128,0,0>>>,RotateColorsX<Variation,Red>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
   "Emperors Hand"},

	{ "Mara (Lightside);common", "tracks/Mara.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb16<14386,0,65535>>,RotateColorsX<Variation,Rgb16<8729,0,40112>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

	//Purple CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb16<14386,0,65535> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb16<14386,0,65535>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	 "Mara"},


	{ "Revan (Lightside);common", "tracks/KOTOR.wav",    StylePtr<Layers<Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,50>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,110>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Magenta>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<Magenta,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Magenta,TrFade<400>>,TrConcat<TrInstant,Magenta,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<Magenta,AudioFlicker<DeepPink,Magenta>,50,1>,TrConcat<TrInstant,AlphaL<Magenta,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Magenta,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Magenta>,ResponsiveBlastL<Magenta,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<DeepPink,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<Magenta,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Magenta,DeepPink>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<Red,700>,TrWipeInSparkTip<Red,300>>>>(),

		//Purple CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<95,0,210> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>>,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Revan"},

	{ "Revan (Darkside);common", "tracks/KOTOR2.wav",    StylePtr<Layers<Stripes<6000,-1750,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<21301,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<DarkOrange>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Orange,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<1000>>,Stripes<1500,2000,DarkOrange,Red>,Stripes<1500,-2500,DarkOrange,Red>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<DarkOrange,AudioFlicker<DarkOrange,Orange>,50,1>,TrConcat<TrInstant,AlphaL<Orange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Orange,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange>,ResponsiveBlastL<Orange,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<Orange,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<Magenta,700>,TrWipeInSparkTip<Magenta,1000>>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Revan"},

	{ "Satele;common", "tracks/KOTOR.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,SteelBlue>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),

		//Light Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,135,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Satele"},

	{ "Trooper Saber;common", "tracks/Vader.wav",    StylePtr<Layers<StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,SteelBlue>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Cyan>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<400>>>>(),

		//Light Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<2,72,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Trooper"},



	//Games

	{ "Cal Kestis;common", "tracks/Fallen.wav",    StylePtr<Layers<Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<30000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<600>,TrWipeIn<600>,Black>>>(),

		//Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Kestis"},


	{ "Trilla;common", "tracks/Trilla.wav",    StylePtr<Layers<Stripes<10000,-1700,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,RotateColorsX<Variation,Red>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<500>,Black>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Trilla"},



   { "Galen Marek (Starkiller) TFU;common", "tracks/Starkiller.wav",
    StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>>>(),

		//Red CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),
	"Starkiller"},


   { "Kyle Katarn - Jedi Outcast;common", "tracks/Katarn.wav",    StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveClashL<White,TrInstant,TrFade<400>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

	   //Blue CC

	/* copyright Fett263 Rotoscope (Crystal Chamber) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Rotoscope
	OS6.7 v4.021
	Single Style
	Base Style: Hyper Responsive Rotoscope (Original Trilogy)


	Base Color: Rgb<0,0,255> (0)

	--Effects Included--
	Preon Effect: Pulsing (Base Color)
	Ignition Effect: Instant
	Retraction Effect: Fade Out
	*/
	StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,InOutTrL<TrInstant,TrFadeX<RetractionTime<0>>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>>>(),"Katarn"},


};
BladeConfig blades[] = {
 { 0, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<1, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >()
  , CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
