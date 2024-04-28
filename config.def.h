/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int gappx     = 5;        /* gaps between windows */
static unsigned int smartgaps     = 1;        /* smartgaps=1 dont show gaps when only one window */
static const unsigned int snap      = 32;       /* snap pixel */
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
		 /*               fg           bg           border   */
		 [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
		 [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

static Inset default_inset = {
	.x = 0,
	.y = 0,
	.w = 0,
	.h = 0,
};

/* tagging */
static char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "TTT",      bstack },
	{ "=[]",      tile_reversed },
	{ "LLL",      bstack_reversed },
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "normbgcolor",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },
		{ "normfgcolor",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor },
		{ "selbordercolor",     STRING,  &selbordercolor },
		{ "selfgcolor",         STRING,  &selfgcolor },
		{ "borderpx",          	INTEGER, &borderpx },
		{ "gappx",          	INTEGER, &gappx },
		{ "smartgaps",          	INTEGER, &smartgaps },
};

/* key definitions */
#define MODKEY Mod1Mask

/* button definitions */
/* click can be ClkTagBar, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

static const char *dwmfifo = "/tmp/dwm.fifo";
static Command commands[] = {
	{ "focusstack",      focusstack,         .parse = parseplusminus },
	{ "incnmaster",      incnmaster,         .parse = parseplusminus },
	{ "setmfact",        setmfact,           .parse = parseplusminusfloat },
	{ "zoom",            zoom,               {0} },
	{ "killclient",      killclient,         {0} },
	{ "togglefloating",  togglefloating,     {0} },
	{ "layoutscroll",    layoutscroll,       .parse = parseplusminus },
	{ "focusmon",        focusmon,           .parse = parseplusminus },
	{ "tagmon",          tagmon,             .parse = parseplusminus },
	{ "pushdown",        pushdown,           {0} },
	{ "pushup",          pushup,             {0} },
	{ "view",            view,               .parse = parsetag },
	{ "toggleview",      toggleview,         .parse = parsetag },
	{ "tag",             tag,                .parse = parsetag },
	{ "toggletag",       toggletag,          .parse = parsetag },
	{ "refresh",         refresh_xresources,               {0} },
	{ "focusmaster",     focusmaster,               {0} },
	{ "quit",            quit,               {0} },
};
