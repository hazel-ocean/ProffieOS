#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1200
const unsigned int maxLedsPerStrip = 128;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD

#define ENABLE_SERIAL
#define DISABLE_DIAGNOSTIC_COMMANDS
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define FETT263_MULTI_PHASE
#define SAVE_STATE

#define FETT263_TWIST_ON_NO_BM 
#define FETT263_TWIST_ON 
#define FETT263_TWIST_OFF    

#define FETT263_STAB_ON_NO_BM                                              
#define FETT263_STAB_ON                                

#define FETT263_SWING_ON_SPEED 500
#define FETT263_SWING_ON_NO_BM
#define FETT263_SWING_ON
#define FETT263_SWING_OFF

#define MOTION_TIMEOUT 60 * 3 * 1000  

#define FETT263_THRUST_ON
#define FETT263_THRUST_OFF
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_DISABLE_CHANGE_FONT
#define ENABLE_SSD1306
// Max 20 characters
#define BLE_PASSWORD "your password"
// Max 32 characters.
#define BLE_NAME "Your Saber Name"
// Max 9 characters
#define BLE_SHORTNAME "Saber"

#define MOTION_TIMEOUT 60 * 3 * 800               
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"

#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {  

{ "Dooku;common", "tracks/Dooku.wav",
    StylePtr<Layers<
  Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>,Mix<Int<7710>,Rgb<64,2,0>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>,Mix<Int<19276>,Rgb<64,2,0>,RgbArg<BASE_COLOR_ARG,Rgb<64,2,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>>,
  AlphaL<RotateColorsX<Variation,Rgb<255,8,0>>,SwingSpeed<300>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,125,0>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SwingSpeed<200>,Int<14000>,Int<18000>>>>,
    AlphaL<Rgb<255,125,0>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14599>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,125,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,TransitionEffect<Rgb<255,125,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<255,125,0>,NavajoWhite,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<NavajoWhite,Int<20000>>,Rgb<255,100,100>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,NavajoWhite,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<255,125,0>,NavajoWhite,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<NavajoWhite,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,100,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Sparkle<OrangeRed,LemonChiffon,20000,650>,BrownNoiseFlicker<OrangeRed,LemonChiffon,300>,TrInstant,TrFade<300>,EFFECT_BLAST>,Rgb<255,100,0>,TrInstant,TrDelay<150>,EFFECT_BLAST>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<14000>>>,TrFade<600>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,125,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<DarkOrange,Rgb<255,125,0>,20,20>,BrownNoiseFlicker<Orange,Rgb<255,125,0>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Yellow,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<350>,TrWipeIn<650>>>>(),
  StylePtr<Layers<
  Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>,Mix<Int<7710>,Rgb<64,2,0>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>,Mix<Int<19276>,Rgb<64,2,0>,RgbArg<BASE_COLOR_ARG,Rgb<64,2,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<128,4,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<96,3,0>>>,
  AlphaL<RotateColorsX<Variation,Rgb<255,8,0>>,SwingSpeed<300>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,125,0>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SwingSpeed<200>,Int<14000>,Int<18000>>>>,
    AlphaL<Rgb<255,125,0>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<14599>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,125,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,TransitionEffect<Rgb<255,125,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<255,125,0>,NavajoWhite,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<NavajoWhite,Int<20000>>,Rgb<255,100,100>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,NavajoWhite,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<255,125,0>,NavajoWhite,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<NavajoWhite,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,100,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Sparkle<OrangeRed,LemonChiffon,20000,650>,BrownNoiseFlicker<OrangeRed,LemonChiffon,300>,TrInstant,TrFade<300>,EFFECT_BLAST>,Rgb<255,100,0>,TrInstant,TrDelay<150>,EFFECT_BLAST>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<14000>>>,TrFade<600>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,125,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<DarkOrange,Rgb<255,125,0>,20,20>,BrownNoiseFlicker<Orange,Rgb<255,125,0>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Yellow,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<350>,TrWipeIn<650>>>>(), "chunRed"},

{ "luke;common", "tracks/luke.wav",
//***************************************
//Luke-EP6GreenRandomFlickerBladestyle
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<33,245,23>>,RotateColorsX<Variation,Rgb<17,123,12>>>,AlphaL<Rgb<34,255,24>,SwingSpeed<300>>,
LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,155,5>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<LemonChiffon,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,LemonChiffon,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
TransitionEffectL<TrConcat<TrInstant,Rgb<33,245,23>,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Red,OrangeRed,DarkOrange,Tomato,OrangeRed,Red>,SmoothStep<Int<28000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,OrangeRed>,Bump<Scale<BladeAngle<>,Int<12000>,Int<24000>>,Int<8000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<12000>,Int<24000>>>,StripesX<Int<1600>,Int<-2000>,RgbArg<BLAST_COLOR_ARG,OrangeRed>,Mix<Int<2096>,Rgb<128,28,0>,RgbArg<BLAST_COLOR_ARG,OrangeRed>>>>,Bump<Scale<BladeAngle<>,Int<12000>,Int<24000>>,Int<32000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<12000>,Int<24000>>>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,GreenYellow,20,20>,BrownNoiseFlicker<LemonChiffon,Rgb<108,192,6>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<20000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<5000>>>,TrDelay<30>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,80>>,AlphaL<White,Bump<Int<0>,Int<2000>>>,TrFade<30>,AlphaL<White,Bump<Int<0>,Int<4000>>>,TrFade<30>,AlphaL<White,Bump<Int<0>,Int<7000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<4000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<2000>>>,TrDelay<30>>,EFFECT_RETRACTION>,
LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
LockupTrL<AlphaL<Mix<TwistAngle<>,OrangeRed,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
InOutTrL<TrWipe<350>,TrWipeIn<850>,Black>>>(),
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<33,245,23>>,RotateColorsX<Variation,Rgb<17,123,12>>>,AlphaL<Rgb<34,255,24>,SwingSpeed<300>>,
LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,155,5>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<LemonChiffon,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,LemonChiffon,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,White>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
TransitionEffectL<TrConcat<TrInstant,Rgb<33,245,23>,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Red,OrangeRed,DarkOrange,Tomato,OrangeRed,Red>,SmoothStep<Int<28000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,OrangeRed>,Bump<Scale<BladeAngle<>,Int<12000>,Int<24000>>,Int<8000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<12000>,Int<24000>>>,StripesX<Int<1600>,Int<-2000>,RgbArg<BLAST_COLOR_ARG,OrangeRed>,Mix<Int<2096>,Rgb<128,28,0>,RgbArg<BLAST_COLOR_ARG,OrangeRed>>>>,Bump<Scale<BladeAngle<>,Int<12000>,Int<24000>>,Int<32000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<12000>,Int<24000>>>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,Moccasin,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<LemonChiffon,GreenYellow,20,20>,BrownNoiseFlicker<LemonChiffon,Rgb<108,192,6>,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,NavajoWhite,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<20000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<5000>>>,TrDelay<30>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,80>>,AlphaL<White,Bump<Int<0>,Int<2000>>>,TrFade<30>,AlphaL<White,Bump<Int<0>,Int<4000>>>,TrFade<30>,AlphaL<White,Bump<Int<0>,Int<7000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<4000>>>,TrDelay<30>,AlphaL<White,Bump<Int<0>,Int<2000>>>,TrDelay<30>>,EFFECT_RETRACTION>,
LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
LockupTrL<AlphaL<Mix<TwistAngle<>,OrangeRed,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
InOutTrL<TrWipe<350>,TrWipeIn<850>,Black>>>(),
 "RoTJ"},

 { "Graflex;common", "tracks/venus.wav",
//************************************************
//TLJGraflexBlueAudioFlickerBladestyle+BrightSwing
StylePtr<Layers<
  Layers<
    AudioFlicker<Rgb<50,115,255>,Rgb<25,58,128>>>,
  AlphaL<RotateColorsX<Variation,Rgb<70,135,255>>,SwingSpeed<300>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Moccasin>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Moccasin,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Int<15000>>>>,TrConcat<TrInstant,AlphaL<Moccasin,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Int<20000>>>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,Moccasin,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,AliceBlue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<OrangeRed>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Red>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Red>,Mix<Int<2096>,OrangeRed,RgbArg<BLAST_COLOR_ARG,Red>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<26000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>,
  ResponsiveClashL<Moccasin,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<100,165,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Rgb<100,165,255>,300>,TrWipeIn<800>>>>(),
StylePtr<Layers<
  Layers<
    AudioFlicker<Rgb<50,115,255>,Rgb<25,58,128>>>,
  AlphaL<RotateColorsX<Variation,Rgb<70,135,255>>,SwingSpeed<300>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Moccasin>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Moccasin,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Int<15000>>>>,TrConcat<TrInstant,AlphaL<Moccasin,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<5000>,Int<44000>>,Int<5000>>,Int<20000>>>,TrFade<300>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,Moccasin,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,AliceBlue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<OrangeRed>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Red>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Red>,Mix<Int<2096>,OrangeRed,RgbArg<BLAST_COLOR_ARG,Red>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<26000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>,
  ResponsiveClashL<Moccasin,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<100,165,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Rgb<100,165,255>,300>,TrWipeIn<800>>>>(), "chunblue"},

//    { "SmthGrey;common", "tracks/mercury.wav",
// StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Green,Chartreuse,0,5>,White,200>,White>,800,800>>(),
// StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Green,Chartreuse,0,5>,White,200>,White>,800,800>>(),"KYLO2"},

   { "QGJ;common", "tracks/QGJ.wav",
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), "chungreen"},
  { "Windu;common", "tracks/Windu.wav",
//********************************************
//MaceWindu-EP3CustomPurpleRotoscopeBladestyle
StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<24000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-1400>,Int<-100>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,Mix<Int<7710>,Rgb<87,7,128>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,Mix<Int<19276>,Rgb<87,7,128>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,
  LockupTrL<Layers<
    AlphaL<Blinking<Rgb<255,100,0>,Strobe<Rgb<255,155,5>,Rgb<128,78,3>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
    AlphaL<Blinking<BrownNoiseFlicker<Rgb<255,100,0>,Rgb<192,75,0>,50>,BrownNoiseFlicker<Rgb<255,155,5>,Rgb<128,78,3>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<Rgb<255,100,0>,Strobe<BrownNoiseFlicker<Rgb<255,155,5>,Rgb<128,78,3>,500>,Coral,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<255,155,5>,Rgb<128,78,3>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Rgb<255,155,5>,Int<20000>>,Rgb<128,78,3>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,DarkOrange,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<255,155,5>,Rgb<128,78,3>,15,1>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Coral,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<BrownNoiseFlicker<White,White,50>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  TransitionEffectL<TrConcat<TrInstant,OrangeRed,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,Rgb<180,0,0>,Rgb<128,0,0>,Rgb<80,0,0>,OrangeRed,DarkOrange>,SmoothStep<Int<25000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>,Mix<Int<2096>,Rgb<67,14,0>,RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<26000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,155,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Rgb<255,155,0>,Coral,20,20>,BrownNoiseFlicker<Rgb<255,155,0>,Coral,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<255,155,0>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<20000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,Rgb<230,230,230>,Rgb<115,115,115>,Rgb<65,65,65>,Rgb<15,15,15>>,Stripes<2000,3000,Rgb<230,230,230>,Rgb<115,115,115>,Rgb<65,65,65>,Rgb<15,15,15>>>,SmoothStep<Scale<TwistAngle<>,Int<30000>,Int<28000>>,Int<3500>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<450>,TrWipeIn<750>>>>(),
  //********************************************
//MaceWindu-EP3CustomPurpleRotoscopeBladestyle
StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<24000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-1400>,Int<-100>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,Mix<Int<7710>,Rgb<87,7,128>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>,Mix<Int<19276>,Rgb<87,7,128>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<173,13,255>>>,
  LockupTrL<Layers<
    AlphaL<Blinking<Rgb<255,100,0>,Strobe<Rgb<255,155,5>,Rgb<128,78,3>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
    AlphaL<Blinking<BrownNoiseFlicker<Rgb<255,100,0>,Rgb<192,75,0>,50>,BrownNoiseFlicker<Rgb<255,155,5>,Rgb<128,78,3>,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<Rgb<255,100,0>,Strobe<BrownNoiseFlicker<Rgb<255,155,5>,Rgb<128,78,3>,500>,Coral,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrSmoothFade<250>,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<Rgb<255,155,5>,Rgb<128,78,3>,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<18000>>>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Rgb<255,155,5>,Int<20000>>,Rgb<128,78,3>,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,DarkOrange,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
  TransitionEffectL<TrConcat<TrInstant,Strobe<Rgb<255,155,5>,Rgb<128,78,3>,15,1>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Coral,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  ResponsiveLightningBlockL<BrownNoiseFlicker<White,White,50>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  TransitionEffectL<TrConcat<TrInstant,OrangeRed,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,Rgb<180,0,0>,Rgb<128,0,0>,Rgb<80,0,0>,OrangeRed,DarkOrange>,SmoothStep<Int<25000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>,Mix<Int<2096>,Rgb<67,14,0>,RgbArg<BLAST_COLOR_ARG,Rgb<228,55,0>>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<26000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,Rgb<255,155,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Rgb<255,155,0>,Coral,20,20>,BrownNoiseFlicker<Rgb<255,155,0>,Coral,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<255,155,0>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<20000>>>,TrFade<600>>,EFFECT_CLASH>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Stripes<1000,3000,Rgb<230,230,230>,Rgb<115,115,115>,Rgb<65,65,65>,Rgb<15,15,15>>,Stripes<2000,3000,Rgb<230,230,230>,Rgb<115,115,115>,Rgb<65,65,65>,Rgb<15,15,15>>>,SmoothStep<Scale<TwistAngle<>,Int<30000>,Int<28000>>,Int<3500>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<450>,TrWipeIn<750>>>>(), "chunzise"},
{ "Shin;common", "tracks/Shin.wav",
  StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OrangeRed,White>,AudioFlicker<OrangeRed,White>>,White>,300,800>>(),
  StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OrangeRed,White>,AudioFlicker<OrangeRed,White>>,White>,300,800>>(),"Shin"},
    { "SmthFuzz;common", "tracks/uranus.wav",
    StyleFirePtr<Red,Yellow>(),
    StyleFirePtr<Red,Yellow>(), "fire"},
{ "AhsokaTM;common", "tracks/AhsokaTM.wav",
   StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Snow,Blue,50>>,White>,300,800>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<BrownNoiseFlicker<Snow,Blue,50>>,White>,300,800>>(), "snowblue"},
   { "DV3;common", "tracks/DV3.wav",
 StyleFirePtr<RandomBlink<3,Red,Red>,Yellow,1,0,10>(),
    StyleFirePtr<RandomBlink<3,Red,Red>,Yellow,1,0,10>(), "KYLO"},
{ "luke5;common", "tracks/luke5.wav",
    StylePtr<InOutHelper<RandomPerLEDFlicker<Pulsing<Blue,InOutHelper<White,300,800>,800>,Blue>,300,800>>(),
    StylePtr<InOutHelper<RandomPerLEDFlicker<Pulsing<Blue,InOutHelper<White,300,800>,800>,Blue>,300,800>>(), "BLUEFLASH"},
{ "TthCrstl;common", "tracks/venus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<HotPink,Yellow>>,GreenYellow>,300,800>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<HotPink,Yellow>>,GreenYellow>,300,800>>(), "PINK"},
{ "Fire;common", "tracks/Fire.wav",
StylePtr<InOutHelper<EasyBlade<OnSpark<Gradient<Cylon<Red,5,20,Red,30,20,1>,GhostWhite,Cylon<Red,5,20,Red,5,20,1>>>,White>,300,800>>(),
StylePtr<InOutHelper<EasyBlade<OnSpark<Gradient<Cylon<Red,5,20,Red,30,20,1>,GhostWhite,Cylon<Red,5,20,Red,5,20,1>>>,White>,300,800>>(), "Cylonwhite"},
{ "TeensySF;common", "tracks/mars.wav",
 StylePtr<InOutHelper<EasyBlade<Stripes<1000,1000,Cyan,Magenta,Yellow,Blue>,White>,300,800>>(),
 StylePtr<InOutHelper<EasyBlade<Stripes<1000,1000,Cyan,Magenta,Yellow,Blue>,White>,300,800>>(), "rainbow"},
{ "SmthJedi;common", "tracks/venus.wav",
StylePtr<InOutHelper<EasyBlade<OnSpark<InOutTr<Azure,TrColorCycle<3000>,TrFade<500>,Green>>,White>,300,800>>(),
StylePtr<InOutHelper<EasyBlade<OnSpark<InOutTr<Azure,TrColorCycle<3000>,TrFade<500>,Green>>,White>,300,800>>(), "greenflash"},
{ "RgueCmdr;common", "tracks/venus.wav",
StylePtr<InOutHelper<EasyBlade<OnSpark<TransitionLoop<Red,TrConcat<TrFade<1000>,GreenYellow,TrFade<200>>>>,White>,300,800>>(),
StylePtr<InOutHelper<EasyBlade<OnSpark<TransitionLoop<Red,TrConcat<TrFade<1000>,GreenYellow,TrFade<200>>>>,White>,300,800>>(), "CC"},
{ "luke4;common", "tracks/luke4.wav",
StylePtr<InOutHelper<EasyBlade<OnSpark<Gradient<Blue,AudioFlicker<White,Blue>,Red,RandomFlicker<Yellow,Blue>>>,White>,300,800>>(),
StylePtr<InOutHelper<EasyBlade<OnSpark<Gradient<Blue,AudioFlicker<White,Blue>,Red,RandomFlicker<Yellow,Blue>>>,White>,300,800>>(), "KK"},
   { "Rey;common", "tracks/Re.wav",
StylePtr<InOutHelper<EasyBlade<Sparkle<OrangeRed>,White>,300,800>>(),
StylePtr<InOutHelper<EasyBlade<Sparkle<OrangeRed>,White>,300,800>>(), "sparkstar"},
  { "Vortex;common", "tracks/Vortex.wav",
StylePtr<Layers<StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,0,0>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,
BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,
FireConfig<2,3000,0>,FireConfig<2,3000,0>>,AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,
Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,
Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,White,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,
SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,
HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,SparkleL<White,100,400>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,
EFFECT_RETRACTION>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,
SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,
Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrFade<300>>,
TrConcat<TrWipe<200>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,
Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,
Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,
Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,
Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Black,
TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Black,TrInstant>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,
AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrFade<2000>,
AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,
AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>>>(),
StylePtr<Layers<StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,0,0>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,
BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,
FireConfig<2,3000,0>,FireConfig<2,3000,0>>,AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,
Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,
Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,White,TrJoinR<TrWipe<100>,TrWipeIn<100>>>,
SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,
HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,SparkleL<White,100,400>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,
EFFECT_RETRACTION>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,
SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,
Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,
Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrFade<300>>,
TrConcat<TrWipe<200>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,
Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,
Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,
Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,
Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<255,0,0>>>,TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Black,
TrWaveX<RotateColorsX<Variation,Rgb<255,0,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Black,TrInstant>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,
AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrFade<2000>,
AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,
AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<255,0,0>>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>>>(),"tsb"},
};
BladeConfig blades[] = {
 { 0, WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<30, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >()
  , CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
