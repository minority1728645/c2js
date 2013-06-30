typedef struct js_Array
{
	void *value;
	int length;
	struct js_Array (*concat)(struct js_Array,...);
	int (*indexOf)(char*);
	char* (*join)(char*);
	int (*lastIndexOf)(char*);
	char* (*pop)();
	int (*push)(char*);
	void (*reverse)();
	char* (*shift)();
	struct js_Array (*slice)(int,int);
	void (*sort)();
	void (*splice)(int,int,...);
	char* (*toString)();
	char* (*unshift)(char*,...);
	struct js_Array (*valueOf)();
} Array;

typedef struct js_Boolean
{
	char* (*toString)();
	struct js_Boolean (*valueOf)();
} Boolean;

typedef struct js_Date
{
	void* (*Date)();
    void* (*getDate)();
    void* (*getDay)();
    void* (*getMonth)();
    void* (*getFullYear)();
    void* (*getYear)();
    void* (*getHours)();
    void* (*getMinutes)();
    void* (*getSeconds)();
    void* (*getMilliseconds)();
    void* (*getTime)();
    void* (*getTimezoneOffset)();
    void* (*getUTCDate)();
    void* (*getUTCDay)();
    void* (*getUTCMonth)();
    void* (*getUTCFullYear)();
    void* (*getUTCHours)();
    void* (*getUTCMinutes)();
    void* (*getUTCSeconds)();
    void* (*getUTCMilliseconds)();
    void* (*parse)();
    void* (*setDate)();
    void* (*setMonth)();
    void* (*setFullYear)();
    void* (*setYear)();
    void* (*setHours)();
    void* (*setMinutes)();
    void* (*setSeconds)();
    void* (*setMilliseconds)();
    void* (*setTime)();
    void* (*setUTCDate)();
    void* (*setUTCMonth)();
    void* (*setUTCFullYear)();
    void* (*setUTCHours)();
    void* (*setUTCMinutes)();
    void* (*setUTCSeconds)();
    void* (*setUTCMilliseconds)();
    void* (*toSource)();
    void* (*toString)();
    void* (*toTimeString)();
    void* (*toDateString)();
    void* (*toGMTString)();
    void* (*toUTCString)();
    void* (*toLocaleString)();
    void* (*toLocaleTimeString)();
    void* (*toLocaleDateString)();
    void* (*UTC)();
    void* (*valueOf)();
} Date;

typedef struct js_Math
{
	double E;
    double LN2;
    double LN10;
    double LOG2E;
    double LOG10E;
    double PI;
    double SQRT1_2;
    double SQRT2;
    double (*abs)(double x);
    double (*acos)(double x);
    double (*asin)(double x);
    double (*atan)(double x);
    double (*atan2)(double y,double x);
    double (*ceil)(double x);
    double (*cos)(double x);
    double (*exp)(double x);
    double (*floor)(double x);
    double (*log)(double x);
    double (*max)(double x,double y);
    double (*min)(double x,double y);
    double (*pow)(double x,double y);
    double (*random)();
    double (*round)(double x);
    double (*sin)(double x);
    double (*sqrt)(double x);
    double (*tan)(double x);
    void* (*toSource)();
    void* (*valueOf)();
} Math;

typedef struct js_Number
{
    double MAX_VALUE;
    double MIN_VALUE;
    double NaN;
    double NEGATIVE_INFINITY;
    double POSITIVE_INFINITY;
    void* (*toString)(double);
    void* (*toLocaleString)(double);
    void* (*toFixed)(double);
    void* (*toExponential)(double);
    void* (*toPrecision)(double);
    void* (*valueOf)(double);
} Number;

typedef struct js_String
{
    double length;
    void* (*anchor)();
    void* (*big)();
    void* (*blink)();
    void* (*bold)();
    void* (*charAt)();
    void* (*charCodeAt)();
    void* (*concat)();
    void* (*fixed)();
    void* (*fontcolor)();
    void* (*fontsize)();
    void* (*fromCharCode)();
    void* (*indexOf)();
    void* (*italics)();
    void* (*lastIndexOf)();
    void* (*link)();
    void* (*localeCompare)();
    void* (*match)();
    void* (*replace)();
    void* (*search)();
    void* (*slice)();
    void* (*small)();
    void* (*split)();
    void* (*strike)();
    void* (*sub)();
    void* (*substr)();
    void* (*substring)();
    void* (*sup)();
    void* (*toLocaleLowerCase)();
    void* (*toLocaleUpperCase)();
    void* (*toLowerCase)();
    void* (*toUpperCase)();
    void* (*toString)();
    void* (*valueOf)();
} String;

typedef struct js_RegExp
{
    double compile;
    double exec;
    double test;
    void* (*search)();
    void* (*match)();
    void* (*replace)();
    void* (*split)();
} RegExp;

typedef struct js_Window
{
    void* closed;
    double defaultStatus;
    void* document;
    void* history;
    double innerheight;
    double innerwidth;
    double location;
    double name;
    void* Navigator;
    double opener;
    double outerheight;
    double outerwidth;
    void* Screen;
    double self;
    double status;
    double top;
    void* (*alert)();
    void* (*blur)();
    void* (*clearInterval)();
    void* (*clearTimeout)();
    void* (*close)();
    void* (*confirm)();
    void* (*createPopup)();
    void* (*focus)();
    void* (*moveBy)();
    void* (*moveTo)();
    void* (*open)();
    void* (*print)();
    void* (*prompt)();
    void* (*resizeBy)();
    void* (*resizeTo)();
    void* (*scrollBy)();
    void* (*scrollTo)();
    void* (*setInterval)();
    void* (*setTimeout)();
} Window;


typedef struct js_Document
{
    void* body;
    void* cookie;
    void* domain;
    void* lastModified;
    void* referrer;
    void* title;
    void* URL;
    void* (*close)();
    void* (*getElementById)();
    void* (*getElementsByName)();
    void* (*getElementsByTagName)();
    void* (*open)();
    void* (*write)(void*);
    void* (*writeln)();
} Document;


typedef struct js_Navigator
{
    double appCodeName;
    double appMinorVersion;
    double appName;
    double appVersion;
    double browserLanguage;
    double cookieEnabled;
    double cpuClass;
    double onLine;
    double platform;
    double systemLanguage;
    double userAgent;
    double userLanguage;
    void* (*javaEnabled)();
    void* (*taintEnabled)();

} Navigator;

typedef struct js_Screen
{
    double availHeight;
    double availWidth;
    double bufferDepth;
    double colorDepth;
    double deviceXDPI;
    double deviceYDPI;
    double fontSmoothingEnabled;
    double height;
    double logicalXDPI;
    double logicalYDPI;
    double pixelDepth;
    double updateInterval;
    double width;
} Screen;

typedef struct js_History
{
    double length;
    void* (*back)();
    void* (*forward)();
    void* (*go)();
} History;

typedef struct js_Location
{
    double hash;
    double host;
    double hostname;
    double href;
    double pathname;
    double port;
    double protocol;
    double search;
    void* (*assign)();
    void* (*reload)();
    void* (*replace)();
} Location;



void* (*decodeURI)(void*);
void* (*decodeURIComponent)(void*);
void* (*encodeURI)(void*);
void* (*encodeURIComponent)(void*);
void* (*escape)(void*);
void* (*eval)(void*);
void* (*getClass)(void*);
void* (*isFinite)(void*);
void* (*isNaN)(void*);
void* (*parseFloat)(void*);
void* (*parseInt)(void*);
void* (*unescape)(void*);





Window window;
Document document;
