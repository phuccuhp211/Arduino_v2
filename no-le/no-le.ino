#include <Wire.h>
unsigned long jikan;
int uad;
/* ---------------------------------------------------------------------------------------------------- */
int tg_ht1, tg_ht4, tg_ht2, tg_ht5, tg_ht3, tg_ht6, tg_ht7, tg_ht8;
float tanso1,    tanso2,    tanso3;
int stt_ts1 = 0, stt_ts2 = 0, stt_ts3 = 0, stt_ts4 = 0, stt_ts5 = 0, stt_ts6 = 0, stt_ts7 = 0, stt_ts8 = 0;
/* ---------------------------------------------------------------------------------------------------- */
int line_qwe = 0, line_asd = 0, line_zxc = 0;
int kpr = 0, krl = 0;
int kpr_nole = 0, krl_nole = 0;
float brnon, brnoff, brnon2, brnoff2, brnon3, brnoff3, brn_ao;
/* ---------------------------------------------------------------------------------------------------- */ 
int led_1 = 13, led_2 = 12, led_3 = 11, led_4 = 10, led_5 = 5, led_6 = 4, led_7 = 3, led_8 = 2;
int fa1 = 1, fa2 = 1, fa3 = 1, fa4 = 1, fa5 = 1, fa6 = 1, fa7 = 1, fa8 = 1;
/* ---------------------------------------------------------------------------------------------------- */
float brn1 = 0, brn2 = 0, brn3 = 0, brn4 = 0, brn5 = 0, brn6 = 0, brn7 = 0, brn8 = 0;
float brncl_1 = 0, brncl_2 = 0, brncl_3 = 0;
float oncl_1 = 0,  oncl_2 = 0,  oncl_3 = 0;
float offcl_1 = 0, offcl_2 = 0, offcl_3 = 0;
float fa_c_cl_1= 0,fa_c_cl_2= 0,fa_c_cl_3= 0;
float fa_t_cl_1= 0,fa_t_cl_2= 0,fa_t_cl_3= 0;
float hsbx_1 = 0, hsbx_2 = 0, hsbx_3 = 0;
/* ---------------------------------------------------------------------------------------------------- */
int ctn1 = 0, ctn2 = 0, ctn3 = 0, ctn4 = 0, ctn5 = 0, ctn6 = 0, ctn7 = 0, ctn8 = 0;
int ctn1b = 0, ctn2b = 0, ctn3b = 0, ctn4b = 0, ctn5b = 0, ctn6b = 0, ctn7b = 0, ctn8b = 0;
int ctn1c = 0, ctn2c = 0, ctn3c = 0, ctn4c = 0, ctn5c = 0, ctn6c = 0, ctn7c = 0, ctn8c = 0;
int ctn1c2 = 0, ctn2c2 = 0, ctn3c2 = 0, ctn4c2 = 0, ctn5c2 = 0, ctn6c2 = 0, ctn7c2 = 0, ctn8c2 = 0;
/* ---------------------------------------------------------------------------------------------------- */
int ctn1_2 = 0, ctn2_2 = 0, ctn3_2 = 0, ctn4_2 = 0, ctn5_2 = 0, ctn6_2 = 0, ctn7_2 = 0, ctn8_2 = 0;
int ctn1b_2 = 0, ctn2b_2 = 0, ctn3b_2 = 0, ctn4b_2 = 0, ctn5b_2 = 0, ctn6b_2 = 0, ctn7b_2 = 0, ctn8b_2 = 0;
int ctn1c_2 = 0, ctn2c_2 = 0, ctn3c_2 = 0, ctn4c_2 = 0, ctn5c_2 = 0, ctn6c_2 = 0, ctn7c_2 = 0, ctn8c_2 = 0;
int ctn1c2_2 = 0, ctn2c2_2 = 0, ctn3c2_2 = 0, ctn4c2_2 = 0, ctn5c2_2 = 0, ctn6c2_2 = 0, ctn7c2_2 = 0, ctn8c2_2 = 0;
/* ---------------------------------------------------------------------------------------------------- */
int ctn1_3 = 0, ctn2_3 = 0, ctn3_3 = 0, ctn4_3 = 0, ctn5_3 = 0, ctn6_3 = 0, ctn7_3 = 0, ctn8_3 = 0;
int ctn1b_3 = 0, ctn2b_3 = 0, ctn3b_3 = 0, ctn4b_3 = 0, ctn5b_3 = 0, ctn6b_3 = 0, ctn7b_3 = 0, ctn8b_3 = 0;
int ctn1c_3 = 0, ctn2c_3 = 0, ctn3c_3 = 0, ctn4c_3 = 0, ctn5c_3 = 0, ctn6c_3 = 0, ctn7c_3 = 0, ctn8c_3 = 0;
int ctn1c2_3 = 0, ctn2c2_3 = 0, ctn3c2_3 = 0, ctn4c2_3 = 0, ctn5c2_3 = 0, ctn6c2_3 = 0, ctn7c2_3 = 0, ctn8c2_3 = 0;
/* ---------------------------------------------------------------------------------------------------- */
float fa_c1 = 0,   fa_c2 = 0,   fa_c3 = 0;
float fa_t1 = 0,   fa_t2 = 0,   fa_t3 = 0;
/* ---------------------------------------------------------------------------------------------------- */
int effhigh = 0,   efflow = 0,   mainbrn,   brntd = 0;
int effhigh_2 = 0, efflow_2 = 0, mainbrn_2, brntd_2 = 0;
int effhigh_3 = 0, efflow_3 = 0, mainbrn_3, brntd_3 = 0;
/* ---------------------------------------------------------------------------------------------------- */
const int pottd = A2;   const int potbrn = A3;    const int potlow = A0;    const int pothigh = A1;
const int pottd2 = A6;  const int potbrn2 = A7;   const int potlow2 = A4;   const int pothigh2 = A5;
const int pottd3 = A10;  const int potbrn3 = A11;   const int potlow3 = A8;  const int pothigh3 = A9;
/* ---------------------------------------------------------------------------------------------------- */

void setup() {
  Serial.begin(9600);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  kpr_nole = Wire.read();
  krl_nole = Wire.read();
  kpr = kpr_nole;
  krl = krl_nole;
}
void loop() {
  jikan = millis();
  
  if ( kpr == 95 ) {line_qwe = 1;}
  if ( kpr == 96 ) {line_qwe = 2;}
  if ( kpr == 97 ) {line_qwe = 3;}
  if ( kpr == 92 ) {line_asd = 1;}
  if ( kpr == 93 ) {line_asd = 2;}
  if ( kpr == 94 ) {line_asd = 3;}
  if ( kpr == 89 ) {line_zxc = 1;}
  if ( kpr == 90 ) {line_zxc = 2;}
  if ( kpr == 91 ) {line_zxc = 3;}

  get_num_val();
  calculator_val();
  effect_cac();
}
void get_num_val() {
  tanso1 = get_pot_val("tanso", 1);
  brnon = brnoff = get_pot_val("brn", 1);
  fa_c1 = get_pot_val("fa_c", 1);
  fa_t1 = get_pot_val("fa_t", 1);

  tanso2 = get_pot_val("tanso", 2);
  brnon2 = brnoff2 = get_pot_val("brn", 2);
  fa_c2 = get_pot_val("fa_c", 2);
  fa_t2 = get_pot_val("fa_t", 2);

  tanso3 = get_pot_val("tanso", 3);
  brnon3 = brnoff3 = get_pot_val("brn", 3);
  fa_c3 = get_pot_val("fa_c", 3);
  fa_t3 = get_pot_val("fa_t", 3);
} 
int get_pot_val(String datatype, int namepot) {
  if (datatype.equals("tanso")) {
    if (namepot == 1) brntd = analogRead(pottd);
    else if (namepot == 2) brntd = analogRead(pottd2);
    else if (namepot == 3) brntd = analogRead(pottd3);

    if ( brntd >= 1000 ) return 60;
    else if ( brntd >= 950 ) return 58;
    else if ( brntd >= 900 ) return 56;
    else if ( brntd >= 850 ) return 54;
    else if ( brntd >= 800 ) return 52;
    else if ( brntd >= 750 ) return 50;
    else if ( brntd >= 700 ) return 48;
    else if ( brntd >= 650 ) return 46;
    else if ( brntd >= 600 ) return 44;
    else if ( brntd >= 550 ) return 42;
    else if ( brntd >= 500 ) return 40;
    else if ( brntd >= 450 ) return 38;
    else if ( brntd >= 400 ) return 36;
    else if ( brntd >= 350 ) return 34;
    else if ( brntd >= 300 ) return 32;
    else if ( brntd >= 250 ) return 30;
    else if ( brntd >= 200 ) return 28;
    else if ( brntd >= 150 ) return 26;
    else if ( brntd >= 100 ) return 24;
    else if ( brntd >= 50 ) return 22;
    else if ( brntd >= 0 ) return 20;
  }
  else if (datatype.equals("brn")) {
    if (namepot == 1) mainbrn = analogRead(potbrn);
    else if (namepot == 2) mainbrn = analogRead(potbrn2);
    else if (namepot == 3) mainbrn = analogRead(potbrn3);

    mainbrn = mainbrn / 4;
    if ( mainbrn >= 255) return 0;
    else if ( mainbrn >= 240) return 15;
    else if ( mainbrn >= 225) return 30;
    else if ( mainbrn >= 210) return 45;
    else if ( mainbrn >= 195) return 60;
    else if ( mainbrn >= 180) return 75;
    else if ( mainbrn >= 165) return 90;
    else if ( mainbrn >= 150) return 105;
    else if ( mainbrn >= 135) return 120;
    else if ( mainbrn >= 120) return 135;
    else if ( mainbrn >= 105) return 150;
    else if ( mainbrn >= 90) return 165;
    else if ( mainbrn >= 75) return 180;
    else if ( mainbrn >= 60) return 195;
    else if ( mainbrn >= 45) return 210;
    else if ( mainbrn >= 30) return 225;
    else if ( mainbrn >= 15) return 240;
    else if ( mainbrn >= 0) return 250;
  } 
  else if (datatype.equals("fa_c") || datatype.equals("fa_t")) {
    if (datatype.equals("fa_c")) {
      if (namepot == 1) uad = analogRead(pothigh);
      else if (namepot == 2) uad = analogRead(pothigh2);
      else if (namepot == 3) uad = analogRead(pothigh3);
    }
    else if (datatype.equals("fa_t")) {
      if (namepot == 1) uad = analogRead(potlow);
      else if (namepot == 2) uad = analogRead(potlow2);
      else if (namepot == 3) uad = analogRead(potlow3);
    }  

    uad = uad / 4;
    if (uad >= 255) return 20;
    else if (uad >= 240) return 17;
    else if (uad >= 225) return 16;
    else if (uad >= 210) return 15;
    else if (uad >= 195) return 14;
    else if (uad >= 180) return 13;
    else if (uad >= 165) return 12;
    else if (uad >= 150) return 11;
    else if (uad >= 135) return 10;
    else if (uad >= 120) return 9;
    else if (uad >= 105) return 8;
    else if (uad >= 90) return 7;
    else if (uad >= 75) return 6;
    else if (uad >= 60) return 5;
    else if (uad >= 45) return 4;
    else if (uad >= 30) return 3;
    else if (uad >= 15) return 2;
    else if (uad >= 0) return 1;
  }
}
void calculator_val() {
    if ( tanso1 == 20 ) hsbx_1 = 1;
    else if ( tanso1 != 20 ) hsbx_1 = tanso1/20;
    if ( brnon == 250 ) { fa_c_cl_1 = fa_c1 * hsbx_1;   fa_t_cl_1 = fa_t1 * hsbx_1; }
    else if ( brnon != 250 ) { brncl_1 = brnon / 250;   fa_c_cl_1 = fa_c1 * brncl_1 * hsbx_1;   fa_t_cl_1 = fa_t1 * brncl_1 * hsbx_1; }

    if ( tanso2 == 20 ) hsbx_2 = 1;
    else if ( tanso2 != 20 ) hsbx_2 = tanso2/20;
    if ( brnon2 == 250 ) { fa_c_cl_2 = fa_c2 * hsbx_2;   fa_t_cl_2 = fa_t2 * hsbx_2; }
    else if ( brnon2 != 250 ) { brncl_2 = brnon2 / 250;   fa_c_cl_2 = fa_c2 * brncl_2 * hsbx_2;   fa_t_cl_2 = fa_t2 * brncl_2 * hsbx_2; }

    if ( tanso3 == 20 ) hsbx_3 = 1;
    else if ( tanso3 != 20 ) hsbx_3 = tanso3/20;
    if ( brnon3 == 250 ) { fa_c_cl_3 = fa_c3 * hsbx_3;   fa_t_cl_3 = fa_t3 * hsbx_3; }
    else if ( brnon3 != 250 ) { brncl_3 = brnon3 / 250;   fa_c_cl_3 = fa_c3 * brncl_3 * hsbx_3;   fa_t_cl_3 = fa_t3 * brncl_3 * hsbx_3; }
}
void led_control(int led, float brn = 0) {
  if (led != 0) analogWrite(led, brn);
  else {
    analogWrite(led_1, brn);
    analogWrite(led_2, brn);
    analogWrite(led_3, brn);
    analogWrite(led_4, brn);
    analogWrite(led_5, brn);
    analogWrite(led_6, brn);
  } 
}
void eff_1_inc(unsigned long &jikan, int &tg_ht, float &tanso, float &brn, float &brnon, float &fa_c, float &fa_t, int &ctn, int &fa, int &stt_ts, int led, int &kpr, int &krl) {
  if( jikan - tg_ht >= tanso ) {
    tg_ht = millis();
    if ( brn <= brnon && fa == 1 ) { brn = brn + fa_c; if ( brn >= brnon ) fa = 2; }
    if ( fa == 2) { brn = brn - fa_t; }
    if ( brn <= 0 ) {brn = 0; ctn = 0; kpr = 0; krl = 0;}
    if ( tanso >= 21) {
      if ( stt_ts == 0 ) { led_control(led, brn); stt_ts = 1;}
      else { led_control(led); stt_ts = 0;}
    }
    else led_control(led, brn);
  }
}
void eff_1_dec(int led, float &brn, int &ctn, int &fa, int &kpr, int &krl) {
  led_control(led);
  brn = 0; ctn = 0; fa = 1; kpr = 0; krl = 0;
}
void eff_2_iad(unsigned long &jikan, int &tg_ht, float &tanso, float &brn, float &brnon, float &fa_c, float &fa_t, int &ctn, int &fa, int &stt_ts, int led, int &kpr, int &krl) {
  if(jikan - tg_ht >= tanso) {
    tg_ht = millis();
    if ( brn <= brnon && fa == 1 ) { brn = brn + (fa_c * 4); if ( brn >= brnon ) fa = 2; }
    if ( fa == 2) { brn = brn - fa_t; }
    if ( brn <= 0 ) {brn = 0; ctn = 0; kpr = 0; krl = 0;}
    if ( tanso >= 21) {
      if ( stt_ts == 0 ) { led_control(led, brn); stt_ts = 1;}
      else { led_control(led); stt_ts = 0;}
    }
    else led_control(led, brn);
  }
}
void eff_3_inc(unsigned long &jikan, int &tg_ht, float &tanso, float &brn, float &brnon, float &fa_c, int &stt_ts, int led) {
  if(jikan - tg_ht >= tanso) { tg_ht = millis();
    if( brn <= brnon) { brn = brn + fa_c; if( brn >= brnon ) brn = brnon; }
    if( brn >= brnon ) brn = brnon;
    if (tanso >= 21) {
      if ( stt_ts == 0 ) { led_control(led, brn); stt_ts = 1; }
      else { led_control(led); stt_ts = 0; }
    }
    else led_control(led, brn);
  }
}
void eff_3_dec(unsigned long &jikan, int &tg_ht, float &tanso, float &brn, float &fa_t, int &stt_ts, int led, int &ctn1, int &ctn2, int &kpr, int &krl) {
  if(jikan - tg_ht >= tanso) { tg_ht = millis();
    brn = brn - fa_t;
    if( brn < 0 ) { brn = 0; ctn1 = 0; ctn2 = 0; stt_ts = 0; kpr = 0; krl = 0; }
    if (tanso >= 21) {
      if ( stt_ts == 0 ) { led_control(led, brn); stt_ts = 1; }
      else { led_control(led); stt_ts = 0; }
    }
    else led_control(led, brn);
  }
}
void effect_cac() {
  ////////////////////////////////////////////////////////////////////////
  //////////////////////////////   LINE 1   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if( line_qwe == 1 ) {
    if (kpr == 20) { ctn1 = 1; reset_eff_nor();}
    if (ctn1 == 1) eff_1_inc(jikan, tg_ht1, tanso1, brn1, brnon, fa_c_cl_1, fa_t_cl_1, ctn1, fa1, stt_ts1, led_1, kpr, krl);
    if (krl == 20) eff_1_dec(led_1, brn1, ctn1, fa1, kpr, krl);

    if (kpr == 26) { ctn2 = 1; reset_eff_nor();}
    if (ctn2 == 1) eff_1_inc(jikan, tg_ht2, tanso1, brn2, brnon, fa_c_cl_1, fa_t_cl_1, ctn2, fa2, stt_ts2, led_2, kpr, krl);
    if (krl == 26) eff_1_dec(led_2, brn2, ctn2, fa2, kpr, krl);

    if (kpr == 8) { ctn3 = 1; reset_eff_nor();}
    if (ctn3 == 1) eff_1_inc(jikan, tg_ht3, tanso1, brn3, brnon, fa_c_cl_1, fa_t_cl_1, ctn3, fa3, stt_ts3, led_3, kpr, krl);
    if (krl == 8) eff_1_dec(led_3, brn3, ctn3, fa3, kpr, krl);

    if (kpr == 21) { ctn4 = 1; reset_eff_nor();}
    if (ctn4 == 1) eff_1_inc(jikan, tg_ht4, tanso1, brn4, brnon, fa_c_cl_1, fa_t_cl_1, ctn4, fa4, stt_ts4, led_4, kpr, krl);
    if (krl == 21) eff_1_dec(led_4, brn4, ctn4, fa4, kpr, krl);

    if (kpr == 23) { ctn5 = 1; reset_eff_nor();}
    if (ctn5 == 1) eff_1_inc(jikan, tg_ht5, tanso1, brn5, brnon, fa_c_cl_1, fa_t_cl_1, ctn5, fa5, stt_ts5, led_5, kpr, krl);
    if (krl == 23) eff_1_dec(led_5, brn5, ctn5, fa5, kpr, krl);

    if (kpr == 28) { ctn6 = 1; reset_eff_nor();}
    if (ctn6 == 1) eff_1_inc(jikan, tg_ht6, tanso1, brn6, brnon, fa_c_cl_1, fa_t_cl_1, ctn6, fa6, stt_ts6, led_6, kpr, krl);
    if (krl == 28) eff_1_dec(led_6, brn6, ctn6, fa6, kpr, krl);

    if (kpr == 24) { ctn7 = 1; reset_eff_nor();}
    if (ctn7 == 1) eff_1_inc(jikan, tg_ht7, tanso1, brn7, brnon, fa_c_cl_1, fa_t_cl_1, ctn7, fa7, stt_ts7, led_7, kpr, krl);
    if (krl == 24) eff_1_dec(led_7, brn7, ctn7, fa7, kpr, krl);

    if (kpr == 12) { ctn8 = 1; reset_eff_nor();}
    if (ctn8 == 1) eff_1_inc(jikan, tg_ht8, tanso1, brn8, brnon, fa_c_cl_1, fa_t_cl_1, ctn8, fa8, stt_ts8, led_8, kpr, krl);
    if (krl == 12) eff_1_dec(led_8, brn8, ctn8, fa8, kpr, krl);
  }
  if( line_qwe == 2 ) {
    if ( kpr == 20 ) { ctn1b = 1; reset_eff_nor(); brn1 = brnoff;}
    if ( ctn1b == 1 ) eff_2_iad(jikan, tg_ht1, tanso1, brn1, brnon, fa_c_cl_1, fa_t_cl_1, ctn1b, fa1, stt_ts1, led_1, kpr, krl);

    if ( kpr == 26 ) { ctn2b = 1; reset_eff_nor(); brn2 = brnoff;}
    if ( ctn2b == 1 ) eff_2_iad(jikan, tg_ht2, tanso1, brn2, brnon, fa_c_cl_1, fa_t_cl_1, ctn2b, fa2, stt_ts2, led_2, kpr, krl);

    if ( kpr == 8 ) { ctn3b = 1; reset_eff_nor(); brn3 = brnoff;}
    if ( ctn3b == 1 ) eff_2_iad(jikan, tg_ht3, tanso1, brn3, brnon, fa_c_cl_1, fa_t_cl_1, ctn3b, fa3, stt_ts3, led_3, kpr, krl);

    if ( kpr == 21 ) { ctn4b = 1; reset_eff_nor(); brn4 = brnoff;}
    if ( ctn4b == 1 ) eff_2_iad(jikan, tg_ht4, tanso1, brn4, brnon, fa_c_cl_1, fa_t_cl_1, ctn4b, fa4, stt_ts4, led_4, kpr, krl);
  
    if ( kpr == 23 ) { ctn5b = 1; reset_eff_nor(); brn5 = brnoff;}
    if ( ctn5b == 1 ) eff_2_iad(jikan, tg_ht5, tanso1, brn5, brnon, fa_c_cl_1, fa_t_cl_1, ctn5b, fa5, stt_ts5, led_5, kpr, krl);
  
    if ( kpr == 28 ) { ctn6b = 1; reset_eff_nor(); brn6 = brnoff;}
    if ( ctn6b == 1 ) eff_2_iad(jikan, tg_ht6, tanso1, brn6, brnon, fa_c_cl_1, fa_t_cl_1, ctn6b, fa6, stt_ts6, led_6, kpr, krl);

    if ( kpr == 24 ) { ctn7b = 1; reset_eff_nor(); brn6 = brnoff;}
    if ( ctn7b == 1 ) eff_2_iad(jikan, tg_ht7, tanso1, brn7, brnon, fa_c_cl_1, fa_t_cl_1, ctn7b, fa7, stt_ts7, led_7, kpr, krl);

    if ( kpr == 12 ) { ctn8b = 1; reset_eff_nor(); brn6 = brnoff;}
    if ( ctn8b == 1 ) eff_2_iad(jikan, tg_ht8, tanso1, brn8, brnon, fa_c_cl_1, fa_t_cl_1, ctn8b, fa8, stt_ts8, led_8, kpr, krl);
  }
  if( line_qwe == 3 ) {
    if ( kpr == 20 ) { ctn1c = 1; ctn1c2 = 0; reset_eff_nor();}
    if ( ctn1c == 1 && ctn1c2 == 0) eff_3_inc(jikan, tg_ht1, tanso1, brn1, brnon, fa_c_cl_1, stt_ts1, led_1);
    if ( krl == 20 ) { ctn1c = 0; ctn1c2 = 1; stt_ts1 = 0;}
    if ( krl == 20 ) { kpr = 0; krl = 0; }
    if ( ctn1c == 0 && ctn1c2 == 1 ) eff_3_dec(jikan, tg_ht1, tanso1, brn1, fa_t_cl_1, stt_ts1, led_1, ctn1c, ctn1c2, kpr, krl);

    if ( kpr == 26 ) { ctn2c = 1; ctn2c2 = 0; reset_eff_nor();}
    if ( ctn2c == 1 && ctn2c2 == 0) eff_3_inc(jikan, tg_ht2, tanso1, brn2, brnon, fa_c_cl_1, stt_ts2, led_2);
    if ( krl == 26 ) { ctn2c = 0; ctn2c2 = 1; stt_ts2 = 0;}
    if ( krl == 26 ) { kpr = 0; krl = 0; }
    if ( ctn2c == 0 && ctn2c2 == 1 ) eff_3_dec(jikan, tg_ht2, tanso1, brn2, fa_t_cl_1, stt_ts2, led_2, ctn2c, ctn2c2, kpr, krl);

    if ( kpr == 8 ) { ctn3c = 1; ctn3c2 = 0; reset_eff_nor();}
    if ( ctn3c == 1 && ctn3c2 == 0) eff_3_inc(jikan, tg_ht3, tanso1, brn3, brnon, fa_c_cl_1, stt_ts3, led_3);
    if ( krl == 8 ) { ctn3c = 0; ctn3c2 = 1; stt_ts3 = 0;}
    if ( krl == 8 ) { kpr = 0; krl = 0; }
    if ( ctn3c == 0 && ctn3c2 == 1 ) eff_3_dec(jikan, tg_ht3, tanso1, brn3, fa_t_cl_1, stt_ts3, led_3, ctn3c, ctn3c2, kpr, krl);

    if ( kpr == 21 ) { ctn4c = 1; ctn4c2 = 0; reset_eff_nor();}
    if ( ctn4c == 1 && ctn4c2 == 0) eff_3_inc(jikan, tg_ht4, tanso1, brn4, brnon, fa_c_cl_1, stt_ts4, led_4);
    if ( krl == 21 ) { ctn4c = 0; ctn4c2 = 1; stt_ts4 = 0;}
    if ( krl == 21 ) { kpr = 0; krl = 0; }
    if ( ctn4c == 0 && ctn4c2 == 1 ) eff_3_dec(jikan, tg_ht4, tanso1, brn4, fa_t_cl_1, stt_ts4, led_4, ctn4c, ctn4c2, kpr, krl);

    if ( kpr == 23 ) { ctn5c = 1; ctn5c2 = 0; reset_eff_nor();}
    if ( ctn5c == 1 && ctn5c2 == 0) eff_3_inc(jikan, tg_ht5, tanso1, brn5, brnon, fa_c_cl_1, stt_ts5, led_5);
    if ( krl == 23 ) { ctn5c = 0; ctn5c2 = 1; stt_ts5 = 0;}
    if ( krl == 23 ) { kpr = 0; krl = 0; }
    if ( ctn5c == 0 && ctn5c2 == 1 ) eff_3_dec(jikan, tg_ht5, tanso1, brn5, fa_t_cl_1, stt_ts5, led_5, ctn5c, ctn5c2, kpr, krl);
  
    if ( kpr == 28 ) { ctn6c = 1; ctn6c2 = 0; reset_eff_nor();}
    if ( ctn6c == 1 && ctn6c2 == 0) eff_3_inc(jikan, tg_ht6, tanso1, brn6, brnon, fa_c_cl_1, stt_ts6, led_6);
    if ( krl == 28 ) { ctn6c = 0; ctn6c2 = 1; stt_ts6 = 0;}
    if ( krl == 28 ) { kpr = 0; krl = 0; }
    if ( ctn6c == 0 && ctn6c2 == 1 ) eff_3_dec(jikan, tg_ht6, tanso1, brn6, fa_t_cl_1, stt_ts6, led_6, ctn6c, ctn6c2, kpr, krl);

    if ( kpr == 24 ) { ctn7c = 1; ctn7c2 = 0; reset_eff_nor();}
    if ( ctn7c == 1 && ctn7c2 == 0) eff_3_inc(jikan, tg_ht7, tanso1, brn7, brnon, fa_c_cl_1, stt_ts7, led_7);
    if ( krl == 24 ) { ctn7c = 0; ctn7c2 = 1; stt_ts7 = 0;}
    if ( krl == 24 ) { kpr = 0; krl = 0; }
    if ( ctn7c == 0 && ctn7c2 == 1 ) eff_3_dec(jikan, tg_ht7, tanso1, brn7, fa_t_cl_1, stt_ts7, led_7, ctn7c, ctn7c2, kpr, krl);

    if ( kpr == 12 ) { ctn8c = 1; ctn8c2 = 0; reset_eff_nor();}
    if ( ctn8c == 1 && ctn8c2 == 0) eff_3_inc(jikan, tg_ht8, tanso1, brn8, brnon, fa_c_cl_1, stt_ts8, led_8);
    if ( krl == 12 ) { ctn8c = 0; ctn8c2 = 1; stt_ts8 = 0;}
    if ( krl == 12 ) { kpr = 0; krl = 0; }
    if ( ctn8c == 0 && ctn8c2 == 1 ) eff_3_dec(jikan, tg_ht8, tanso1, brn8, fa_t_cl_1, stt_ts8, led_8, ctn8c, ctn8c2, kpr, krl);
  }


  
  ////////////////////////////////////////////////////////////////////////
  //////////////////////////////   LINE 2   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if( line_asd == 1 ) {
    if (kpr == 4) { ctn1_2 = 1; reset_eff_nor();}
    if (ctn1_2 == 1) eff_1_inc(jikan, tg_ht1, tanso2, brn1, brnon2, fa_c_cl_2, fa_t_cl_2, ctn1_2, fa1, stt_ts1, led_1, kpr, krl);
    if (krl == 4) eff_1_dec(led_1, brn1, ctn1_2, fa1, kpr, krl);

    if (kpr == 22) { ctn2_2 = 1; reset_eff_nor();}
    if (ctn2_2 == 1) eff_1_inc(jikan, tg_ht2, tanso2, brn2, brnon2, fa_c_cl_2, fa_t_cl_2, ctn2_2, fa2, stt_ts2, led_2, kpr, krl);
    if (krl == 22) eff_1_dec(led_2, brn2, ctn2_2, fa2, kpr, krl);
  
    if (kpr == 7) { ctn3_2 = 1; reset_eff_nor();}
    if (ctn3_2 == 1) eff_1_inc(jikan, tg_ht3, tanso2, brn3, brnon2, fa_c_cl_2, fa_t_cl_2, ctn3_2, fa3, stt_ts3, led_3, kpr, krl);
    if (krl == 7) eff_1_dec(led_3, brn3, ctn3_2, fa3, kpr, krl);
    
    if (kpr == 9) { ctn4_2 = 1; reset_eff_nor();}
    if (ctn4_2 == 1) eff_1_inc(jikan, tg_ht4, tanso2, brn4, brnon2, fa_c_cl_2, fa_t_cl_2, ctn4_2, fa4, stt_ts4, led_4, kpr, krl);
    if (krl == 9) eff_1_dec(led_4, brn4, ctn4_2, fa4, kpr, krl);
    
    if (kpr == 10) { ctn5_2 = 1; reset_eff_nor();}
    if (ctn5_2 == 1) eff_1_inc(jikan, tg_ht5, tanso2, brn5, brnon2, fa_c_cl_2, fa_t_cl_2, ctn5_2, fa5, stt_ts5, led_5, kpr, krl);
    if (krl == 10) eff_1_dec(led_5, brn5, ctn5_2, fa5, kpr, krl);

    if (kpr == 11) { ctn6_2 = 1; reset_eff_nor();}
    if (ctn6_2 == 1) eff_1_inc(jikan, tg_ht6, tanso2, brn6, brnon2, fa_c_cl_2, fa_t_cl_2, ctn6_2, fa6, stt_ts6, led_6, kpr, krl);
    if (krl == 11) eff_1_dec(led_6, brn6, ctn6_2, fa6, kpr, krl);

    if (kpr == 13) { ctn7_2 = 1; reset_eff_nor();}
    if (ctn7_2 == 1) eff_1_inc(jikan, tg_ht7, tanso2, brn7, brnon2, fa_c_cl_2, fa_t_cl_2, ctn7_2, fa7, stt_ts7, led_7, kpr, krl);
    if (krl == 13) eff_1_dec(led_7, brn7, ctn7_2, fa7, kpr, krl);

    if (kpr == 14) { ctn8_2 = 1; reset_eff_nor();}
    if (ctn8_2 == 1) eff_1_inc(jikan, tg_ht8, tanso2, brn8, brnon2, fa_c_cl_2, fa_t_cl_2, ctn8_2, fa8, stt_ts8, led_8, kpr, krl);
    if (krl == 14) eff_1_dec(led_8, brn6, ctn8_2, fa8, kpr, krl);
  }
  if( line_asd == 2 ) {
    if ( kpr == 4 ) { ctn1b_2 = 1; reset_eff_nor(); brn1 = brnoff2;}
    if ( ctn1b_2 == 1 ) eff_2_iad(jikan, tg_ht1, tanso2, brn1, brnon2, fa_c_cl_2, fa_t_cl_2, ctn1b_2, fa1, stt_ts1, led_1, kpr, krl);

    if ( kpr == 22 ) { ctn2b_2 = 1; reset_eff_nor(); brn2 = brnoff2;}
    if ( ctn2b_2 == 1 ) eff_2_iad(jikan, tg_ht2, tanso2, brn2, brnon2, fa_c_cl_2, fa_t_cl_2, ctn2b_2, fa2, stt_ts2, led_2, kpr, krl);
    
    if ( kpr == 7 ) { ctn3b_2 = 1; reset_eff_nor(); brn3 = brnoff2;}
    if ( ctn3b_2 == 1 ) eff_2_iad(jikan, tg_ht3, tanso2, brn3, brnon2, fa_c_cl_2, fa_t_cl_2, ctn3b_2, fa3, stt_ts3, led_3, kpr, krl);
  
    if ( kpr == 9 ) { ctn4b_2 = 1; reset_eff_nor(); brn4 = brnoff2;}
    if ( ctn4b_2 == 1 ) eff_2_iad(jikan, tg_ht4, tanso2, brn4, brnon2, fa_c_cl_2, fa_t_cl_2, ctn4b_2, fa4, stt_ts4, led_4, kpr, krl);
  
    if ( kpr == 10 ) { ctn5b_2 = 1; reset_eff_nor(); brn5 = brnoff2;}
    if ( ctn5b_2 == 1 ) eff_2_iad(jikan, tg_ht5, tanso2, brn5, brnon2, fa_c_cl_2, fa_t_cl_2, ctn5b_2, fa5, stt_ts5, led_5, kpr, krl);
  
    if ( kpr == 11 ) { ctn6b_2 = 1; reset_eff_nor(); brn6 = brnoff2;}
    if ( ctn6b_2 == 1 ) eff_2_iad(jikan, tg_ht6, tanso2, brn6, brnon2, fa_c_cl_2, fa_t_cl_2, ctn6b_2, fa6, stt_ts6, led_6, kpr, krl);

    if ( kpr == 13 ) { ctn7b_2 = 1; reset_eff_nor(); brn7 = brnoff2;}
    if ( ctn7b_2 == 1 ) eff_2_iad(jikan, tg_ht7, tanso2, brn7, brnon2, fa_c_cl_2, fa_t_cl_2, ctn7b_2, fa7, stt_ts7, led_7, kpr, krl);
  
    if ( kpr == 14 ) { ctn8b_2 = 1; reset_eff_nor(); brn8 = brnoff2;}
    if ( ctn8b_2 == 1 ) eff_2_iad(jikan, tg_ht8, tanso2, brn8, brnon2, fa_c_cl_2, fa_t_cl_2, ctn8b_2, fa8, stt_ts8, led_8, kpr, krl);
  }
  if( line_asd == 3 ) {
    if ( kpr == 4 ) { ctn1c_2 = 1; ctn1c2_2 = 0; reset_eff_nor();}
    if ( ctn1c_2 == 1 && ctn1c2_2 == 0) eff_3_inc(jikan, tg_ht1, tanso2, brn1, brnon2, fa_c_cl_2, stt_ts1, led_1);
    if ( krl == 4 ) { ctn1c_2 = 0; ctn1c2_2 = 1; stt_ts1 = 0;}
    if ( krl == 4 ) { kpr = 0; krl = 0; }
    if ( ctn1c_2 == 0 && ctn1c2_2 == 1 ) eff_3_dec(jikan, tg_ht1, tanso2, brn1, fa_t_cl_2, stt_ts1, led_1, ctn1c_2, ctn1c2_2, kpr, krl);

    if ( kpr == 22 ) { ctn2c_2 = 1; ctn2c2_2 = 0; reset_eff_nor();}
    if ( ctn2c_2 == 1 && ctn2c2_2 == 0) eff_3_inc(jikan, tg_ht2, tanso2, brn2, brnon2, fa_c_cl_2, stt_ts2, led_2);
    if ( krl == 22 ) { ctn2c_2 = 0; ctn2c2_2 = 1; stt_ts2 = 0;}
    if ( krl == 22 ) { kpr = 0; krl = 0; }
    if ( ctn2c_2 == 0 && ctn2c2_2 == 1 ) eff_3_dec(jikan, tg_ht2, tanso2, brn2, fa_t_cl_2, stt_ts2, led_2, ctn2c_2, ctn2c2_2, kpr, krl);
  
    if ( kpr == 7 ) { ctn3c_2 = 1; ctn3c2_2 = 0; reset_eff_nor();}
    if ( ctn3c_2 == 1 && ctn3c2_2 == 0) eff_3_inc(jikan, tg_ht3, tanso2, brn3, brnon2, fa_c_cl_2, stt_ts3, led_3);
    if ( krl == 7 ) { ctn3c_2 = 0; ctn3c2_2 = 1; stt_ts3 = 0;}
    if ( krl == 7 ) { kpr = 0; krl = 0; }
    if ( ctn3c_2 == 0 && ctn3c2_2 == 1 ) eff_3_dec(jikan, tg_ht3, tanso2, brn3, fa_t_cl_2, stt_ts3, led_3, ctn3c_2, ctn3c2_2, kpr, krl);
  
    if ( kpr == 9 ) { ctn4c_2 = 1; ctn4c2_2 = 0; reset_eff_nor();}
    if ( ctn4c_2 == 1 && ctn4c2_2 == 0) eff_3_inc(jikan, tg_ht4, tanso2, brn4, brnon2, fa_c_cl_2, stt_ts4, led_4);
    if ( krl == 9 ) { ctn4c_2 = 0; ctn4c2_2 = 1; stt_ts4 = 0;}
    if ( krl == 9 ) { kpr = 0; krl = 0; }
    if ( ctn4c_2 == 0 && ctn4c2_2 == 1 ) eff_3_dec(jikan, tg_ht4, tanso2, brn4, fa_t_cl_2, stt_ts4, led_4, ctn4c_2, ctn4c2_2, kpr, krl);
  
    if ( kpr == 10 ) { ctn5c_2 = 1; ctn5c2_2 = 0; reset_eff_nor();}
    if ( ctn5c_2 == 1 && ctn5c2_2 == 0) eff_3_inc(jikan, tg_ht5, tanso2, brn5, brnon2, fa_c_cl_2, stt_ts5, led_5);
    if ( krl == 10 ) { ctn5c_2 = 0; ctn5c2_2 = 1; stt_ts5 = 0;}
    if ( krl == 10 ) { kpr = 0; krl = 0; }
    if ( ctn5c_2 == 0 && ctn5c2_2 == 1 ) eff_3_dec(jikan, tg_ht5, tanso2, brn5, fa_t_cl_2, stt_ts5, led_5, ctn5c_2, ctn5c2_2, kpr, krl);
  
    if ( kpr == 11 ) { ctn6c_2 = 1; ctn6c2_2 = 0; reset_eff_nor();}
    if ( ctn6c_2 == 1 && ctn6c2_2 == 0) eff_3_inc(jikan, tg_ht6, tanso2, brn6, brnon2, fa_c_cl_2, stt_ts6, led_6);
    if ( krl == 11 ) { ctn6c_2 = 0; ctn6c2_2 = 1; stt_ts6 = 0;}
    if ( krl == 11 ) { kpr = 0; krl = 0; }
    if ( ctn6c_2 == 0 && ctn6c2_2 == 1 ) eff_3_dec(jikan, tg_ht6, tanso2, brn6, fa_t_cl_2, stt_ts6, led_6, ctn6c_2, ctn6c2_2, kpr, krl);

    if ( kpr == 10 ) { ctn7c_2 = 1; ctn7c2_2 = 0; reset_eff_nor();}
    if ( ctn7c_2 == 1 && ctn7c2_2 == 0) eff_3_inc(jikan, tg_ht7, tanso2, brn7, brnon2, fa_c_cl_2, stt_ts7, led_7);
    if ( krl == 10 ) { ctn7c_2 = 0; ctn7c2_2 = 1; stt_ts7 = 0;}
    if ( krl == 10 ) { kpr = 0; krl = 0; }
    if ( ctn7c_2 == 0 && ctn7c2_2 == 1 ) eff_3_dec(jikan, tg_ht7, tanso2, brn7, fa_t_cl_2, stt_ts7, led_7, ctn7c_2, ctn7c2_2, kpr, krl);
  
    if ( kpr == 11 ) { ctn8c_2 = 1; ctn8c2_2 = 0; reset_eff_nor();}
    if ( ctn8c_2 == 1 && ctn8c2_2 == 0) eff_3_inc(jikan, tg_ht8, tanso2, brn8, brnon2, fa_c_cl_2, stt_ts8, led_8);
    if ( krl == 11 ) { ctn8c_2 = 0; ctn8c2_2 = 1; stt_ts8 = 0;}
    if ( krl == 11 ) { kpr = 0; krl = 0; }
    if ( ctn8c_2 == 0 && ctn8c2_2 == 1 ) eff_3_dec(jikan, tg_ht8, tanso2, brn8, fa_t_cl_2, stt_ts8, led_8, ctn8c_2, ctn8c2_2, kpr, krl);
  }
  

  
  ////////////////////////////////////////////////////////////////////////
  //////////////////////////////   LINE 3   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if( line_zxc == 1 ) {
    if (kpr == 29) { ctn1_3 = 1; reset_eff_nor();}
    if (ctn1_3 == 1) eff_1_inc(jikan, tg_ht1, tanso3, brn1, brnon3, fa_c_cl_3, fa_t_cl_3, ctn1_3, fa1, stt_ts1, led_1, kpr, krl);
    if (krl == 29) eff_1_dec(led_1, brn1, ctn1_3, fa1, kpr, krl);

    if (kpr == 27) { ctn2_3 = 1; reset_eff_nor();}
    if (ctn2_3 == 1) eff_1_inc(jikan, tg_ht2, tanso3, brn2, brnon3, fa_c_cl_3, fa_t_cl_3, ctn2_3, fa2, stt_ts2, led_2, kpr, krl);
    if (krl == 27) eff_1_dec(led_2, brn2, ctn2_3, fa2, kpr, krl);
  
    if (kpr == 6) { ctn3_3 = 1; reset_eff_nor();}
    if (ctn3_3 == 1) eff_1_inc(jikan, tg_ht3, tanso3, brn3, brnon3, fa_c_cl_3, fa_t_cl_3, ctn3_3, fa3, stt_ts3, led_3, kpr, krl);
    if (krl == 6) eff_1_dec(led_3, brn3, ctn3_3, fa3, kpr, krl);
  
    if (kpr == 25) { ctn4_3 = 1; reset_eff_nor();}
    if (ctn4_3 == 1) eff_1_inc(jikan, tg_ht4, tanso3, brn4, brnon3, fa_c_cl_3, fa_t_cl_3, ctn4_3, fa4, stt_ts4, led_4, kpr, krl);
    if (krl == 25) eff_1_dec(led_4, brn4, ctn4_3, fa4, kpr, krl);
  
    if (kpr == 5) { ctn5_3 = 1; reset_eff_nor();}
    if (ctn5_3 == 1) eff_1_inc(jikan, tg_ht5, tanso3, brn5, brnon3, fa_c_cl_3, fa_t_cl_3, ctn5_3, fa5, stt_ts5, led_5, kpr, krl);
    if (krl == 5) eff_1_dec(led_5, brn5, ctn5_3, fa5, kpr, krl);
  
    if (kpr == 17) { ctn6_3 = 1; reset_eff_nor();}
    if (ctn6_3 == 1) eff_1_inc(jikan, tg_ht6, tanso3, brn6, brnon3, fa_c_cl_3, fa_t_cl_3, ctn6_3, fa6, stt_ts6, led_6, kpr, krl);
    if (krl == 17) eff_1_dec(led_6, brn6, ctn6_3, fa6, kpr, krl);

    if (kpr == 16) { ctn7_3 = 1; reset_eff_nor();}
    if (ctn7_3 == 1) eff_1_inc(jikan, tg_ht7, tanso3, brn7, brnon3, fa_c_cl_3, fa_t_cl_3, ctn7_3, fa7, stt_ts7, led_7, kpr, krl);
    if (krl == 16) eff_1_dec(led_7, brn7, ctn7_3, fa7, kpr, krl);
  
    if (kpr == 54) { ctn8_3 = 1; reset_eff_nor();}
    if (ctn8_3 == 1) eff_1_inc(jikan, tg_ht8, tanso3, brn8, brnon3, fa_c_cl_3, fa_t_cl_3, ctn8_3, fa8, stt_ts8, led_8, kpr, krl);
    if (krl == 54) eff_1_dec(led_8, brn8, ctn8_3, fa8, kpr, krl);
  }
  if( line_zxc == 2 ) {
    if ( kpr == 29 ) { ctn1b_3 = 1; reset_eff_nor(); brn1 = brnoff3;}
    if ( ctn1b_3 == 1 ) eff_2_iad(jikan, tg_ht1, tanso3, brn1, brnon3, fa_c_cl_3, fa_t_cl_3, ctn1b_3, fa1, stt_ts1, led_1, kpr, krl);

    if ( kpr == 27 ) { ctn2b_3 = 1; reset_eff_nor(); brn2 = brnoff3;}
    if ( ctn2b_3 == 1 ) eff_2_iad(jikan, tg_ht2, tanso3, brn2, brnon3, fa_c_cl_3, fa_t_cl_3, ctn2b_3, fa2, stt_ts2, led_2, kpr, krl);
  
    if ( kpr == 6 ) { ctn3b_3 = 1; reset_eff_nor(); brn3 = brnoff3;}
    if ( ctn3b_3 == 1 ) eff_2_iad(jikan, tg_ht3, tanso3, brn3, brnon3, fa_c_cl_3, fa_t_cl_3, ctn3b_3, fa3, stt_ts3, led_3, kpr, krl);
  
    if ( kpr == 25 ) { ctn4b_3 = 1; reset_eff_nor(); brn4 = brnoff3;}
    if ( ctn4b_3 == 1 ) eff_2_iad(jikan, tg_ht4, tanso3, brn4, brnon3, fa_c_cl_3, fa_t_cl_3, ctn4b_3, fa4, stt_ts4, led_4, kpr, krl);
  
    if ( kpr == 5 ) { ctn5b_3 = 1; reset_eff_nor(); brn5 = brnoff3;}
    if ( ctn5b_3 == 1 ) eff_2_iad(jikan, tg_ht5, tanso3, brn5, brnon3, fa_c_cl_3, fa_t_cl_3, ctn5b_3, fa5, stt_ts5, led_5, kpr, krl);
  
    if ( kpr == 17 ) { ctn6b_3 = 1; reset_eff_nor(); brn6 = brnoff3;}
    if ( ctn6b_3 == 1 ) eff_2_iad(jikan, tg_ht6, tanso3, brn6, brnon3, fa_c_cl_3, fa_t_cl_3, ctn6b_3, fa6, stt_ts6, led_6, kpr, krl);

    if ( kpr == 16 ) { ctn7b_3 = 1; reset_eff_nor(); brn7 = brnoff3;}
    if ( ctn7b_3 == 1 ) eff_2_iad(jikan, tg_ht7, tanso3, brn7, brnon3, fa_c_cl_3, fa_t_cl_3, ctn7b_3, fa7, stt_ts7, led_7, kpr, krl);
  
    if ( kpr == 54 ) { ctn8b_3 = 1; reset_eff_nor(); brn8 = brnoff3;}
    if ( ctn8b_3 == 1 ) eff_2_iad(jikan, tg_ht8, tanso3, brn8, brnon3, fa_c_cl_3, fa_t_cl_3, ctn8b_3, fa8, stt_ts8, led_8, kpr, krl);
  }
  if( line_zxc == 3 ) {
    if ( kpr == 29 ) { ctn1c_3 = 1; ctn1c2_3 = 0; reset_eff_nor();}
    if ( ctn1c_3 == 1 && ctn1c2_3 == 0) eff_3_inc(jikan, tg_ht1, tanso3, brn1, brnon3, fa_c_cl_3, stt_ts1, led_1);
    if ( krl == 29 ) { ctn1c_3 = 0; ctn1c2_3 = 1; stt_ts1 = 0;}
    if ( krl == 29 ) { kpr = 0; krl = 0; }
    if ( ctn1c_3 == 0 && ctn1c2_3 == 1 ) eff_3_dec(jikan, tg_ht1, tanso3, brn1, fa_t_cl_3, stt_ts1, led_1, ctn1c_3, ctn1c2_3, kpr, krl);
  
    if ( kpr == 27 ) { ctn2c_3 = 1; ctn2c2_3 = 0; reset_eff_nor();}
    if ( ctn2c_3 == 1 && ctn2c2_3 == 0) eff_3_inc(jikan, tg_ht2, tanso3, brn2, brnon3, fa_c_cl_3, stt_ts2, led_2);
    if ( krl == 27 ) { ctn2c_3 = 0; ctn2c2_3 = 1; stt_ts2 = 0;}
    if ( krl == 27 ) { kpr = 0; krl = 0; }
    if ( ctn2c_3 == 0 && ctn2c2_3 == 1 ) eff_3_dec(jikan, tg_ht2, tanso3, brn2, fa_t_cl_3, stt_ts2, led_2, ctn2c_3, ctn2c2_3, kpr, krl);
  
    if ( kpr == 6 ) { ctn3c_3 = 1; ctn3c2_3 = 0; reset_eff_nor();}
    if ( ctn3c_3 == 1 && ctn3c2_3 == 0) eff_3_inc(jikan, tg_ht3, tanso3, brn3, brnon3, fa_c_cl_3, stt_ts3, led_3);
    if ( krl == 6 ) { ctn3c_3 = 0; ctn3c2_3 = 1; stt_ts3 = 0;}
    if ( krl == 6 ) { kpr = 0; krl = 0; }
    if ( ctn3c_3 == 0 && ctn3c2_3 == 1 ) eff_3_dec(jikan, tg_ht3, tanso3, brn3, fa_t_cl_3, stt_ts3, led_3, ctn3c_3, ctn3c2_3, kpr, krl);
    
    if ( kpr == 25 ) { ctn4c_3 = 1; ctn4c2_3 = 0; reset_eff_nor();}
    if ( ctn4c_3 == 1 && ctn4c2_3 == 0) eff_3_inc(jikan, tg_ht4, tanso3, brn4, brnon3, fa_c_cl_3, stt_ts4, led_4);
    if ( krl == 25 ) { ctn4c_3 = 0; ctn4c2_3 = 1; stt_ts4 = 0;}
    if ( krl == 25 ) { kpr = 0; krl = 0; }
    if ( ctn4c_3 == 0 && ctn4c2_3 == 1 ) eff_3_dec(jikan, tg_ht4, tanso3, brn4, fa_t_cl_3, stt_ts4, led_4, ctn4c_3, ctn4c2_3, kpr, krl);
  
    if ( kpr == 5 ) { ctn5c_3 = 1; ctn5c2_3 = 0; reset_eff_nor();}
    if ( ctn5c_3 == 1 && ctn5c2_3 == 0) eff_3_inc(jikan, tg_ht5, tanso3, brn5, brnon3, fa_c_cl_3, stt_ts5, led_5);
    if ( krl == 5 ) { ctn5c_3 = 0; ctn5c2_3 = 1; stt_ts5 = 0;}
    if ( krl == 5 ) { kpr = 0; krl = 0; }
    if ( ctn5c_3 == 0 && ctn5c2_3 == 1 ) eff_3_dec(jikan, tg_ht5, tanso3, brn5, fa_t_cl_3, stt_ts5, led_5, ctn5c_3, ctn5c2_3, kpr, krl);
  
    if ( kpr == 17 ) { ctn6c_3 = 1; ctn6c2_3 = 0; reset_eff_nor();}
    if ( ctn6c_3 == 1 && ctn6c2_3 == 0) eff_3_inc(jikan, tg_ht6, tanso3, brn6, brnon3, fa_c_cl_3, stt_ts6, led_6);
    if ( krl == 17 ) { ctn6c_3 = 0; ctn6c2_3 = 1; stt_ts6 = 0;}
    if ( krl == 17 ) { kpr = 0; krl = 0; }
    if ( ctn6c_3 == 0 && ctn6c2_3 == 1 ) eff_3_dec(jikan, tg_ht6, tanso3, brn6, fa_t_cl_3, stt_ts6, led_6, ctn6c_3, ctn6c2_3, kpr, krl);

    if ( kpr == 5 ) { ctn7c_3 = 1; ctn7c2_3 = 0; reset_eff_nor();}
    if ( ctn7c_3 == 1 && ctn7c2_3 == 0) eff_3_inc(jikan, tg_ht7, tanso3, brn7, brnon3, fa_c_cl_3, stt_ts7, led_7);
    if ( krl == 5 ) { ctn7c_3 = 0; ctn7c2_3 = 1; stt_ts7 = 0;}
    if ( krl == 5 ) { kpr = 0; krl = 0; }
    if ( ctn7c_3 == 0 && ctn7c2_3 == 1 ) eff_3_dec(jikan, tg_ht7, tanso3, brn7, fa_t_cl_3, stt_ts7, led_7, ctn7c_3, ctn7c2_3, kpr, krl);
  
    if ( kpr == 17 ) { ctn8c_3 = 1; ctn8c2_3 = 0; reset_eff_nor();}
    if ( ctn8c_3 == 1 && ctn8c2_3 == 0) eff_3_inc(jikan, tg_ht8, tanso3, brn8, brnon3, fa_c_cl_3, stt_ts8, led_8);
    if ( krl == 17 ) { ctn8c_3 = 0; ctn8c2_3 = 1; stt_ts8 = 0;}
    if ( krl == 17 ) { kpr = 0; krl = 0; }
    if ( ctn8c_3 == 0 && ctn8c2_3 == 1 ) eff_3_dec(jikan, tg_ht8, tanso3, brn8, fa_t_cl_3, stt_ts8, led_8, ctn8c_3, ctn8c2_3, kpr, krl);
  }
}
void reset_eff_nor() {
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 1   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 20 ) { fa1 = 1;
    brn1 = (line_qwe == 3) ? brn1 : 0; stt_ts1 = 0;
    ctn1_2 = ctn1b_2 = ctn1c_2 = ctn1c2_2 = 0;
    ctn1_3 = ctn1b_3 = ctn1c_3 = ctn1c2_3 = 0;
  }
  if ( kpr == 4 ) { fa1 = 1;
    brn1 = (line_asd == 3) ? brn1 : 0; stt_ts1 = 0;
    ctn1 = ctn1b = ctn1c = ctn1c2 = 0;
    ctn1_3 = ctn1b_3 = ctn1c_3 = ctn1c2_3 = 0;
  }
  if ( kpr == 29 ) { fa1 = 1;
    brn1 = (line_zxc == 3) ? brn1 : 0 ;stt_ts1 = 0;
    ctn1_2 = ctn1b_2 = ctn1c_2 = ctn1c2_2 = 0;
    ctn1 = ctn1b = ctn1c = ctn1c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 2   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 26 ) { fa2 = 1;
    brn2 = (line_qwe == 3) ? brn2 : 0; stt_ts2 = 0;
    ctn2_2 = ctn2b_2 = ctn2c_2 = ctn2c2_2 = 0;
    ctn2_3 = ctn2b_3 = ctn2c_3 = ctn2c2_3 = 0;
  }
  if ( kpr == 22 ) { fa2 = 1;
    brn2 = (line_asd == 3) ? brn2 : 0; stt_ts2 = 0;
    ctn2 = ctn2b = ctn2c = ctn2c2 = 0;
    ctn2_3 = ctn2b_3 = ctn2c_3 = ctn2c2_3 = 0;
  }
  if ( kpr == 27 ) { fa2 = 1;
    brn2 = (line_zxc == 3) ? brn2 : 0; stt_ts2 = 0;
    ctn2_2 = ctn2b_2 = ctn2c_2 = ctn2c2_2 = 0;
    ctn2 = ctn2b = ctn2c = ctn2c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 3   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 8 ) { fa3 = 1;
    brn3 = (line_qwe == 3) ? brn3 : 0; stt_ts3 = 0;
    ctn3_2 = ctn3b_2 = ctn3c_2 = ctn3c2_2 = 0;
    ctn3_3 = ctn3b_3 = ctn3c_3 = ctn3c2_3 = 0;
  }
  if ( kpr == 7 ) { fa3 = 1;
    brn3 = (line_asd == 3) ? brn3 : 0; stt_ts3 = 0;
    ctn3 = ctn3b = ctn3c = ctn3c2 = 0;
    ctn3_3 = ctn3b_3 = ctn3c_3 = ctn3c2_3 = 0;
  }
  if ( kpr == 6 ) { fa3 = 1;
    brn3 = (line_zxc == 3) ? brn3 : 0; stt_ts3 = 0;
    ctn3_2 = ctn3b_2 = ctn3c_2 = ctn3c2_2 = 0;
    ctn3 = ctn3b = ctn3c = ctn3c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 4   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 21 ) { fa4 = 1;
    brn4 = (line_qwe == 3) ? brn4 : 0; stt_ts4 = 0;
    ctn4_2 = ctn4b_2 = ctn4c_2 = ctn4c2_2 = 0;
    ctn4_3 = ctn4b_3 = ctn4c_3 = ctn4c2_3 = 0;
  }
  if ( kpr == 9 ) { fa4 = 1;
    brn4 = (line_asd == 3) ? brn4 : 0; stt_ts4 = 0;
    ctn4 = ctn4b = ctn4c = ctn4c2 = 0;
    ctn4_3 = ctn4b_3 = ctn4c_3 = ctn4c2_3 = 0;
  }
  if ( kpr == 25 ) { fa4 = 1;
    brn4 = (line_zxc == 3) ? brn4 : 0; stt_ts4 = 0;
    ctn4_2 = ctn4b_2 = ctn4c_2 = ctn4c2_2 = 0;
    ctn4 = ctn4b = ctn4c = ctn4c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 5   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 23 ) { fa5 = 1;
    brn5 = (line_qwe == 3) ? brn5 : 0; stt_ts5 = 0;
    ctn5_2 = ctn5b_2 = ctn5c_2 = ctn5c2_2 = 0;
    ctn5_3 = ctn5b_3 = ctn5c_3 = ctn5c2_3 = 0;
  }
  if ( kpr == 10 ) { fa5 = 1;
    brn5 = (line_asd == 3) ? brn5 : 0; stt_ts5 = 0;
    ctn5 = ctn5b = ctn5c = ctn5c2 = 0;
    ctn5_3 = ctn5b_3 = ctn5c_3 = ctn5c2_3 = 0;
  }
  if ( kpr == 5 ) { fa5 = 1;
    brn5 = (line_zxc == 3) ? brn5 : 0; stt_ts5 = 0;
    ctn5_2 = ctn5b_2 = ctn5c_2 = ctn5c2_2 = 0;
    ctn5 = ctn5b = ctn5c = ctn5c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 6   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 28 ) { fa6 = 1;
    brn6 = (line_qwe == 3) ? brn6 : 0; stt_ts6 = 0;
    ctn6_2 = ctn6b_2 = ctn6c_2 = ctn6c2_2 = 0;
    ctn6_3 = ctn6b_3 = ctn6c_3 = ctn6c2_3 = 0;
  }
  if ( kpr == 11 ) { fa6 = 1;
    brn6 = (line_asd == 3) ? brn6 : 0; stt_ts6 = 0;
    ctn6 = ctn6b = ctn6c = ctn6c2 = 0;
    ctn6_3 = ctn6b_3 = ctn6c_3 = ctn6c2_3 = 0;
  }
  if ( kpr == 17 ) { fa6 = 1;
    brn6 = (line_zxc == 3) ? brn6 : 0; stt_ts6 = 0;
    ctn6_2 = ctn6b_2 = ctn6c_2 = ctn6c2_2 = 0;
    ctn6 = ctn6b = ctn6c = ctn6c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 7   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 24 ) { fa7 = 1;
    brn7 = (line_qwe == 3) ? brn7 : 0; stt_ts7 = 0;
    ctn7_2 = ctn7b_2 = ctn7c_2 = ctn7c2_2 = 0;
    ctn7_3 = ctn7b_3 = ctn7c_3 = ctn7c2_3 = 0;
  }
  if ( kpr == 13 ) { fa7 = 1;
    brn7 = (line_asd == 3) ? brn7 : 0; stt_ts7 = 0;
    ctn7 = ctn7b = ctn7c = ctn7c2 = 0;
    ctn7_3 = ctn7b_3 = ctn7c_3 = ctn7c2_3 = 0;
  }
  if ( kpr == 6 ) { fa7 = 1;
    brn7 = (line_zxc == 3) ? brn7 : 0; stt_ts7 = 0;
    ctn7_2 = ctn7b_2 = ctn7c_2 = ctn7c2_2 = 0;
    ctn7 = ctn7b = ctn7c = ctn7c2 = 0;
  }
  ////////////////////////////////////////////////////////////////////////
  ///////////////////////////////   ROW 8   //////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  if ( kpr == 12 ) { fa6 = 1;
    brn8 = (line_qwe == 3) ? brn8 : 0; stt_ts8 = 0;
    ctn8_2 = ctn8b_2 = ctn8c_2 = ctn8c2_2 = 0;
    ctn8_3 = ctn8b_3 = ctn8c_3 = ctn8c2_3 = 0;
  }
  if ( kpr == 14 ) { fa6 = 1;
    brn8 = (line_asd == 3) ? brn8 : 0; stt_ts8 = 0;
    ctn8 = ctn8b = ctn8c = ctn8c2 = 0;
    ctn8_3 = ctn8b_3 = ctn8c_3 = ctn8c2_3 = 0;
  }
  if ( kpr == 54 ) { fa6 = 1;
    brn8 = (line_zxc == 3) ? brn8 : 0; stt_ts8 = 0;
    ctn8_2 = ctn8b_2 = ctn8c_2 = ctn8c2_2 = 0;
    ctn8 = ctn8b = ctn8c = ctn8c2 = 0;
  }

  kpr = 0; krl = 0;
}