/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 2; /* border pixel of windows */
static const unsigned int gappx_outer = 12;    /* gaps between windows */
static const unsigned int gappx_inner = 12;    /* gaps between windows */
static const unsigned int snap = 32;    /* snap pixel */
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
    [SchemeSel]    = {color0, color3, color7},
    [SchemeStatus] = {color0, color3, color0},
};

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", "" };

static const Rule rules[] = {
    /* class            instance    title       tags mask     isfloating monitor */
    {"Gimp"             , NULL , NULL , 0 , 1 , 0} ,
    {"TeamSpeak 3"      , NULL , NULL , 0 , 1 , 0} ,
    {"KeePassXC"        , NULL , NULL , 0 , 1 , 0} ,
    {"Thunar"           , NULL , NULL , 0 , 1 , 0} ,
    {"Pavucontrol"      , NULL , NULL , 0 , 1 , 0} ,
    {"Steam"            , NULL , NULL , 0 , 1 , 0} ,
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    {"[]=", tile}, /* first entry is default */
    {"<><", NULL}, /* no layout function means floating behavior */
    {"[]", monocle},
    {"|M|", centeredmaster }
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
static const char *runcmd[]     = { "dmenu_run", "-i", "-m", "0", "-p", "Run", NULL};
static const char *termcmd[]    = { "st", NULL};
static const char *rangercmd[]  = { "st", "-e", "ranger", NULL};
static const char *sysmenu[]    = { "/home/peter/.local/scripts/sysmenu", NULL};

/* Brightness */
static const char *brupcmd[]    = { "/home/peter/.local/scripts/backlightadj", "up", NULL};
static const char *brdowncmd[]  = { "/home/peter/.local/scripts/backlightadj", "down", NULL};

/* Volume */
static const char *incvol[]     = { "/home/peter/.local/scripts/voladj", "up", NULL};
static const char *decvol[]     = { "/home/peter/.local/scripts/voladj", "down", NULL};
static const char *mutevol[]    = { "/home/peter/.local/scripts/voladj", "mute", NULL};
static const char *togglevol[]  = { "/home/peter/.local/scripts/voladj", "toggle", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY               , XK_d      , spawn          , {.v = runcmd}}                                      ,
    {MODKEY               , XK_p      , spawn          , {.v = sysmenu}}                                     ,
    {MODKEY               , XK_s      , spawn          , SHCMD("sleep 0.2; /home/peter/.local/scripts/ss")}  ,
    {MODKEY | ShiftMask   , XK_s      , spawn          , SHCMD("sleep 0.2; /home/peter/.local/scripts/screenshot -f")} ,
    {MODKEY | ControlMask , XK_s      , spawn          , SHCMD("sleep 0.2; /home/peter/.local/scripts/screenshot -w")} ,
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
    {MODKEY               , XK_z      , set_gaps_inner , {.i = -5}}                                          ,
    {MODKEY               , XK_x      , set_gaps_inner , {.i = +5}}                                          ,
    {MODKEY | ShiftMask   , XK_z      , set_gaps_outer , {.i = -5}}                                          ,
    {MODKEY | ShiftMask   , XK_x      , set_gaps_outer , {.i = +5}}                                          ,
    {MODKEY | ShiftMask   , XK_e      , quit           , {0}}                                                ,
    TAGKEYS(XK_1, 0),
    TAGKEYS(XK_2, 1),
    TAGKEYS(XK_3, 2),
    TAGKEYS(XK_4, 3),
    TAGKEYS(XK_5, 4),
    TAGKEYS(XK_6, 5),
    TAGKEYS(XK_7, 6),
    TAGKEYS(XK_8, 7)};

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
