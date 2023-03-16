/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int gappx = 8;    /* gaps between windows */
static const unsigned int snap = 8;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"Hack Nerd Font Mono:size=10"};
static char color0[] = "#000000"; // Background
static char color1[] = "#111111";
static char color2[] = "#222222";
static char color3[] = "#333333";
static char color4[] = "#444444";
static char color5[] = "#555555";
static char color6[] = "#666666";
static char color7[] = "#FFFFFF"; // Foreground
static char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm]   = {color7, color0, color0},
    [SchemeSel]    = {color0, color2, color2},
    [SchemeStatus] = {color0, color2, color0},
};

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
    /* class            instance    title       tags mask     isfloating monitor */
    {"TeamSpeak 3"      , NULL , NULL , 0 , 1 , 0} ,
    {"Thunar"           , NULL , NULL , 0 , 1 , 0} ,
    {"Pavucontrol"      , NULL , NULL , 0 , 1 , 0} ,
    {"Nemo"             , NULL , NULL , 0 , 1 , 0} ,
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints = 1; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    {"[]=", tile}, /* first entry is default */
    {"<><", NULL}, /* no layout function means floating behavior */
    {"[]", monocle},
    {"|M|", centeredmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}}

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static const char *druncmd[]     = { "rofi", "-show", "drun", "-show-icons", "-font", "\"hack 10\"", NULL};
static const char *runcmd[]     = { "rofi", "-show", "run", "-show-icons", "-font", "\"hack 10\"", NULL};
static const char *termcmd[]    = { "st", NULL};
static const char *rangercmd[]  = { "st", "-e", "ranger", NULL};
static const char *calccmd[]  = { "/home/peter/.local/scripts/calculate", NULL};
static const char *sysmenu[]    = { "/home/peter/.local/scripts/sysmenu", NULL};
static const char *lockcmd[]    = { "i3lock-fancy-multimonitor", "-b=0x8", NULL}; // Maximum blur

/* Brightness */
static const char *brupcmd[]    = { "doas", "--", "light", "-A", "10", NULL};
static const char *brdowncmd[]  = { "doas", "--", "light", "-U", "10", NULL};

/* Keyboard backlight */
static const char *kbup[]  = { "doas", "--", "rogauracore", "brightness", "1", NULL};
static const char *kbdown[]  = { "doas", "--", "rogauracore", "brightness", "0", NULL};

/* Volume */
static const char *incvol[]     = { "/home/peter/.local/scripts/voladj", "up", NULL};
static const char *decvol[]     = { "/home/peter/.local/scripts/voladj", "down", NULL};
static const char *mutevol[]    = { "/home/peter/.local/scripts/voladj", "mute", NULL};
static const char *togglevol[]  = { "/home/peter/.local/scripts/voladj", "toggle", NULL};

static const char *sscmd[]  = { "flameshot", "gui", "-p", "/home/peter/pictures/screenshots", NULL};
static const char *ssclipcmd[]  = { "flameshot", "gui", "--clipboard", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY               , XK_d      , spawn          , {.v = druncmd}}                                      ,
    {MODKEY | ShiftMask   , XK_d      , spawn          , {.v = runcmd}}                                      ,
    {MODKEY               , XK_p      , spawn          , {.v = sysmenu}}                                     ,
    {MODKEY               , XK_s      , spawn          , {.v = ssclipcmd}}                                     ,
    {MODKEY | ShiftMask   , XK_s      , spawn          , {.v = sscmd}}                                      ,
    {MODKEY | ShiftMask   , XK_c      , spawn          , {.v = calccmd}} ,
    {MODKEY | ShiftMask   , XK_l      , spawn          , {.v = lockcmd}} ,
    {MODKEY               , XK_Return , spawn          , {.v = termcmd}}                                     ,
    {MODKEY               , XK_b      , spawn          , {.v = brupcmd}}                                     ,
    {MODKEY | ShiftMask   , XK_b      , spawn          , {.v = brdowncmd}}                                   ,
    {MODKEY               , XK_r      , spawn          , {.v = rangercmd}}                                   ,
    {MODKEY               , XK_u      , spawn          , {.v = incvol}}                                      ,
    {MODKEY | ShiftMask   , XK_u      , spawn          , {.v = decvol}}                                      ,
    {MODKEY               , XK_y      , spawn          , {.v = togglevol}}                                   ,
    {MODKEY | ShiftMask   , XK_y      , spawn          , {.v = mutevol}}                                     ,
    {MODKEY               , XK_j      , focusstack     , {.i = +1}}                                          ,
    {MODKEY               , XK_k      , focusstack     , {.i = -1}}                                          ,
    {MODKEY               , XK_i      , incnmaster     , {.i = +1}}                                          ,
    {MODKEY | ShiftMask   , XK_i      , incnmaster     , {.i = -1}}                                          ,
    {MODKEY               , XK_h      , setmfact       , {.f = -0.05}}                                       ,
    {MODKEY               , XK_l      , setmfact       , {.f = +0.05}}                                       ,
    {MODKEY | ShiftMask   , XK_Return , zoom           , {0}}                                                ,
    {MODKEY               , XK_q      , killclient     , {0}}                                                ,
    {MODKEY               , XK_t      , setlayout      , {.v = &layouts[0]}}                                 ,
    {MODKEY               , XK_f      , setlayout      , {.v = &layouts[1]}}                                 ,
    {MODKEY               , XK_m      , setlayout      , {.v = &layouts[2]}}                                 ,
    {MODKEY               , XK_c      , setlayout      , {.v = &layouts[3]}}                                 ,
    {MODKEY | ShiftMask   , XK_f      , fullscreen     , {0}}                                                ,
    {MODKEY               , XK_space  , setlayout      , {0}}                                                ,
    {MODKEY | ShiftMask   , XK_space  , togglefloating , {0}}                                                ,
    {MODKEY               , XK_0      , view           , {.ui = ~0}}                                         ,
    {MODKEY | ShiftMask   , XK_0      , tag            , {.ui = ~0}}                                         ,
    {MODKEY               , XK_comma  , focusmon       , {.i = -1}}                                          ,
    {MODKEY               , XK_period , focusmon       , {.i = +1}}                                          ,
    {MODKEY | ShiftMask   , XK_comma  , tagmon         , {.i = -1}}                                          ,
    {MODKEY | ShiftMask   , XK_period , tagmon         , {.i = +1}}                                          ,
    {MODKEY               , XK_z      , set_gaps       , {.i = -4}}                                          ,
    {MODKEY               , XK_x      , set_gaps       , {.i = +4}}                                          ,
    {MODKEY | ShiftMask   , XK_e      , quit           , {0}}                                                ,
    {MODKEY               , XK_F3     , spawn          , {.v = kbup}}                                        ,
    {MODKEY               , XK_F2     , spawn          , {.v = kbdown}}                                        ,
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7),
    TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
