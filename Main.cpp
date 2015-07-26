//---------------------------------------------------------------------------
/*
	TRANSLATE USING SISULIZER!
    	Español translation?

	Fireworks 1-7 might be parsed as 1?
    Corel 10 and 11?
    ACD Systems Canvas X, 9, 8, 7
    Xara Xtreme XML paths not implemented yet
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#include <vcl\registry.hpp>
#include <vcl\inifiles.hpp>
#include <shlobj.h>
#include <sysdefs.h>            // ARRAYSIZE macro
#include <WindowsX.h>           // GlobalFreePtr
#include <FileCtrl.hpp>
#include <dir.h>
#include <algorithm>
#pragma hdrstop
#include <vcl\DateUtils.hpp>

using namespace std;

#include "Progress.h"
#include "ScanProgress.h"
#include "Agreement.h"
#include "Main.h"
#include "strings.rh"

#define FILESCAN_FILEMASK   faReadOnly|faHidden|faSysFile|faArchive|faAnyFile|faDirectory
#define FIRST_DRIVE         "A:\\"
#define LAST_DRIVE          'Z'

#define INIFILE                 "setup.ini"
#define TEMP_DIR                "Software\\VanDerLee\\Temp"
// Temporary paths
#define TEMP_AFTERFX41			"AFX41"
#define TEMP_CANVAS9			"Cv9"
#define TEMP_CANVAS10			"Cv10"
#define TEMP_CANVAS11			"Cv11"
#define TEMP_CANVAS12			"Cv12"
#define TEMP_DIGITALDARKROOM    "DD"
#define TEMP_FIREWORKSn         "Fw"
#define TEMP_FIREWORKS1         "Fw1"
#define TEMP_FIREWORKS2         "Fw2"
#define TEMP_FIREWORKS3         "Fw3"
#define TEMP_FIREWORKS4         "Fw4"
#define TEMP_FIREWORKS5         "Fw5"
#define TEMP_FIREWORKS6         "Fw6"
#define TEMP_FIREWORKS7         "Fw7"
#define TEMP_FIREWORKS8         "Fw8"
#define TEMP_FREEHAND8          "Fh8"
#define TEMP_ILLUSTRATOR7       "I7"
#define TEMP_IMAGEEXPLORERPRO4  "IEP4"
#define TEMP_IMAGENPn  			"INP"
#define TEMP_IMAGENP1           "INP1"
#define TEMP_IMAGENP2           "INP2"
#define TEMP_IMAGENP3           "INP3"
#define TEMP_IMAGENP4           "INP4"
#define TEMP_IMAGENP5           "INP5"
#define TEMP_IMAGENP6           "INP6"
#define TEMP_IMAGENP7           "INP7"
#define TEMP_IMAGENP8           "INP8"
#define TEMP_PAINTER9        	"Pt9"
#define TEMP_PAINTER10        	"Pt10"
#define TEMP_PAINTER11       	"Pt11"
#define TEMP_PAINTER12       	"Pt12"
#define TEMP_PHOTODELUXE        "PDL"
#define TEMP_PHOTODRAW2K1       "PD2KP1"
#define TEMP_PHOTODRAW2K2       "PD2KP2"
#define TEMP_PHOTOIMPACTPn  	"PiP"
#define TEMP_PHOTOIMPACTP1      "PiP1"
#define TEMP_PHOTOIMPACTP2      "PiP2"
#define TEMP_PHOTOIMPACTP3      "PiP3"
#define TEMP_PHOTOIMPACTP4      "PiP4"
#define TEMP_PHOTOIMPACTP5      "PiP5"
#define TEMP_PHOTOIMPACTP6      "PiP6"
#define TEMP_PHOTOIMPACTP7      "PiP7"
#define TEMP_PHOTOIMPACTP8      "PiP8"
#define TEMP_PHOTOIMPACTn 		"Pi"
#define TEMP_PHOTOIMPACT5 		"Pi5"
#define TEMP_PHOTOIMPACT6 		"Pi6"
#define TEMP_PHOTOIMPACT7 		"Pi7"
#define TEMP_PHOTOIMPACT8 		"Pi8"
#define TEMP_PHOTOIMPACT85		"Pi85"
#define TEMP_PHOTOIMPACT9		"Pi9"
#define TEMP_PHOTOIMPACT10		"Pi10"
#define TEMP_PHOTOIMPACT11		"Pi11"
#define TEMP_PHOTOIMPACT12		"Pi12"
#define TEMP_PHOTOIMPACT13		"Pi13"
#define TEMP_PHOTOIMPACT14		"Pi14"
#define TEMP_PHOTOIMPACT15		"Pi15"
#define TEMP_PHOTOLINE5P1       "Pl5P1"
#define TEMP_PHOTOLINE5P2       "Pl5P2"
#define TEMP_PHOTOPAINT9Pn  	"PP9P"
#define TEMP_PHOTOPAINT9P1      "PP9P1"
#define TEMP_PHOTOPAINT9P2      "PP9P2"
#define TEMP_PHOTOPAINT9P3      "PP9P3"
#define TEMP_PHOTOPAINT9P4      "PP9P4"
#define TEMP_PHOTOPAINT9P5      "PP9P5"
#define TEMP_PHOTOPAINT9P6      "PP9P6"
#define TEMP_PHOTOPAINT9P7      "PP9P7"
#define TEMP_PHOTOPAINT9P8      "PP9P8"
#define TEMP_PHOTOPAINT12Pn  	"PP12P"
#define TEMP_PHOTOPAINT12P1     "PP12P1"
#define TEMP_PHOTOPAINT12P2     "PP12P2"
#define TEMP_PHOTOPAINT12P3     "PP12P3"
#define TEMP_PHOTOPAINT12P4     "PP12P4"
#define TEMP_PHOTOPAINT12P5     "PP12P5"
#define TEMP_PHOTOPAINT12P6     "PP12P6"
#define TEMP_PHOTOPAINT12P7     "PP12P7"
#define TEMP_PHOTOPAINT12P8     "PP12P8"
#define TEMP_PHOTOSHOP2         "PS2"
#define TEMP_PHOTOSHOP3         "PS3"
#define TEMP_PHOTOSHOP4         "PS4"
#define TEMP_PREMIERE42         "Pm42"
#define TEMP_QFX7               "QFX7"
#define TEMP_XARAXTREME			"XX"
#define TEMP_XARAXTREMEPn		"XXP"
#define TEMP_XARAXTREMEP1		"XXP1"
#define TEMP_XARAXTREMEP2		"XXP2"
#define TEMP_XARAXTREMEP3		"XXP3"
#define TEMP_XARAXTREMEP4		"XXP4"
#define TEMP_XARAXTREMEP5		"XXP5"
#define TEMP_XARAXTREMEP6		"XXP6"
#define TEMP_XARAXTREMEP7		"XXP7"
#define TEMP_XARAXTREMEP8		"XXP8"
#define TEMP_XARAXTREMEPRO		"XXPr"
#define TEMP_XARAXTREMEPRO1		"XXPrP1"
#define TEMP_XARAXTREMEPRO2		"XXPrP2"
#define TEMP_XARAXTREMEPRO3		"XXPrP3"
#define TEMP_XARAXTREMEPRO4		"XXPrP4"
#define TEMP_XARAXTREMEPRO5		"XXPrP5"
#define TEMP_XARAXTREMEPRO51	"XXPrP51"
#define TEMP_XRES2              "xR2"

AnsiString  asSubDir;

// Application recognition routines!
typedef struct App_struct
{   HKEY    Root;
    char    Key[80];
    char    Name[30];
    char    Info[50];
    bool    Detected;
	bool    Default;
    bool    Folder;
	char    ParentEnabled[30];
    char    Enabled[30];
} App_struct;

App_struct App[] =
{
// AFTER FX
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_AFTERFX41,
        "After FX 4.1 by Adobe", false, true, true,
        "afterfx", "afterfx41"  		},
// AVIEDIT
    {   HKEY_CURRENT_USER, "Software\\Mil AVIedit", "Plug0",
        "AVIedit by Alexander Milukov", false, true, true,
        "aviedit", "aviedit1"           },
// CANVAS
    {   HKEY_CURRENT_USER, "Software\\Deneba\\Canvas 6\\Tools", "Tools_Dir",
        "Canvas 6 by Deneba", false, true, true,
        "canvas", "canvas6"             },
    {   HKEY_CURRENT_USER, "Software\\Deneba\\Canvas 7\\Tools", "Tools_Dir",
        "Canvas 7 by Deneba", false, true, true,
		"canvas", "canvas7"             },
	{   HKEY_CURRENT_USER, "Software\\Deneba\\Canvas 8\\Tools", "Tools_Dir",
		"Canvas 8 by Deneba", false, true, true,
		"canvas", "canvas8"             },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_CANVAS9,
		"Canvas 9 by Deneba/ACD Systems", false, true, true,
		"canvas", "canvas9"             },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_CANVAS10,
		"Canvas X by ACD Systems", false, true, true,
		"canvas", "canvas10"            },
{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_CANVAS11,
		"Canvas 11 by ACD Systems", false, true, true,
		"canvas", "canvas11"            },
	// prediction based on Canvas11
{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_CANVAS12,
		"Canvas 12 by ACD Systems", false, true, true,
		"canvas", "canvas12"            },
// COLORWORKS:WEB
    {   HKEY_CURRENT_USER,
        "Software\\SPG\\ColorWorks\\CWInformationSettings", "PLUGINDIR",
        "ColorWorks: Web 4 by SPG", false, true, true,
        "colorworksweb", "colorworksweb4"   },
// DEBABELIZER
    {   HKEY_CURRENT_USER,
        "Software\\Equilibrium\\DeBabelizer Pro\\4.5.1", "Plugins.Path",
		"Debabelizer 4.5.1 by Equilibrium", false, true, true,
        "debabelizer", "debabelizer451" },
// DEEP PAINT
    {   HKEY_CURRENT_USER,
        "Software\\Right Hemisphere\\Deep Paint\\Directories",
        "Photoshop Plugin Directory",
        "Deep Paint by Right Hemisphere", false, true, true,
        "deeppaint", "deeppaint1"       },
// DIGITAL DARKROOM
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_DIGITALDARKROOM,
        "Digital Darkroom by MicroFrontier", false, true, true,
        "digitaldarkroom", "digitaldarkroom1"   },
// FIREWORKS
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS1,
        "FireWorks by MacroMedia", false, true, true,
        "fireworks", "fireworks1"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS2,
        "FireWorks 2 by MacroMedia", false, true, true,
        "fireworks", "fireworks2"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS3,
        "FireWorks 3 by MacroMedia", false, true, true,
        "fireworks", "fireworks3"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS4,
        "FireWorks 4 by MacroMedia", false, true, true,
        "fireworks", "fireworks4"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS5,
        "FireWorks 5 by MacroMedia", false, true, true,
        "fireworks", "fireworks5"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS6,
        "FireWorks 6 by MacroMedia", false, true, true,
        "fireworks", "fireworks6"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS7,
        "FireWorks 7 by MacroMedia", false, true, true,
        "fireworks", "fireworks7"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FIREWORKS8,
        "FireWorks 8 by MacroMedia", false, true, true,
        "fireworks", "fireworks8"       },
// FREEHAND
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_FREEHAND8,
        "Freehand 8 by MacroMedia", false, true, true,
        "freehand", "freehand8"         },
// GIF ANIMATOR
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\3.0\\PathInfo", "ApsDir1",
        "Gif Animator 3 by Ulead, 1st path", false, true, true,
        "gifanimator", "gifanimator3"   },
    {   HKEY_CURRENT_USER,
		"Software\\Ulead Systems\\Ulead GIF Animator\\3.0\\PathInfo", "ApsDir2",
		"Gif Animator 3 by Ulead, 2nd path", false, false, true,
		"gifanimator", "gifanimator3"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\3.0\\PathInfo", "ApsDir3",
        "Gif Animator 3 by Ulead, 3rd path", false, false, true,
        "gifanimator", "gifanimator3"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\3.0\\PathInfo", "ApsDir4",
        "Gif Animator 3 by Ulead, 4th path", false, false, true,
        "gifanimator", "gifanimator3"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\4.0\\PathInfo", "ApsDir1",
        "Gif Animator 4 by Ulead, 1st path", false, true, true,
        "gifanimator", "gifanimator4"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\4.0\\PathInfo", "ApsDir2",
        "Gif Animator 4 by Ulead, 2nd path", false, false, true,
        "gifanimator", "gifanimator4"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\4.0\\PathInfo", "ApsDir3",
        "Gif Animator 4 by Ulead, 3rd path", false, false, true,
        "gifanimator", "gifanimator4"   },
    {   HKEY_CURRENT_USER,
        "Software\\Ulead Systems\\Ulead GIF Animator\\4.0\\PathInfo", "ApsDir4",
        "Gif Animator 4 by Ulead, 4th path", false, false, true,
        "gifanimator", "gifanimator4"   },
// ILLUSTRATOR
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_ILLUSTRATOR7,
        "Illustrator 7 by Adobe", false, true, true,
        "illustrator", "illustrator7"   },
// IMAGE COMPOSER
    {   HKEY_LOCAL_MACHINE,
        "Software\\Microsoft\\Microsoft Image Composer\\Plug Ins", "Primary Plug In Path",
        "Image Composer 1.0 by Microsoft, 1st path", false, true, false,
        "imagecomposer", "imagecomposer1"   },
    {   HKEY_LOCAL_MACHINE,
        "Software\\Microsoft\\Microsoft Image Composer\\Plug Ins", "Secondary Plug In Path",
        "Image Composer 1.0 by Microsoft, 2nd path", false, false, false,
        "imagecomposer", "imagecomposer1"   },
// IMAGE EXPLORER PRO
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGEEXPLORERPRO4,
        "Image Explorer Pro 4 by CDH Productions", false, true, false,
        "imageexplorerpro", "imageexplorerpro4" },
// IMAGEN
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP1,
        "imageN by PS, 1st path", false, true, true,
		"imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP2,
		"imageN by PS, 2nd path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP3,
        "imageN by PS, 3rd path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP4,
        "imageN by PS, 4th path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP5,
        "imageN by PS, 5th path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP6,
        "imageN by PS, 6th path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP7,
        "imageN by PS, 7th path", false, false, true,
        "imagen", "imagen1"             },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_IMAGENP8,
        "imageN by PS, 8th path", false, false, true,
        "imagen", "imagen1"             },
// IMAGEREADY
    {   HKEY_CURRENT_USER,
        "Software\\Adobe\\ImageReady 2.0\\Preferences", "PluginFolder",
        "ImageReady 2 by Adobe", false, true, true,
        "imageready", "imageready2" },
// PAINTER
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PAINTER9,
        "Painter IX by Corel", false, true, true,
        "painter", "painter9"             },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PAINTER10,
		"Painter X by Corel", false, true, true,
		"painter", "painter10"             },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PAINTER11,
		"Painter 11 by Corel", false, true, true,
		"painter", "painter11"             },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PAINTER12,
		"Painter 12 by Corel", false, true, true,
		"painter", "painter12"             },
// PAINT SHOP PRO
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro\\ImageProcessingFilter", "Directory",
        "Paint Shop Pro 4 by JASC", false, true, true,
        "paintshoppro", "paintshoppro4" },
    // 5
    {   HKEY_CURRENT_USER,
		"Software\\JASC\\Paint Shop Pro 5\\ImageProcessingFilter", "Directory1",
        "Paint Shop Pro 5 by JASC, 1st path", false, true, true,
		"paintshoppro", "paintshoppro5" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 5\\ImageProcessingFilter", "Directory2",
        "Paint Shop Pro 5 by JASC, 2nd path", false, false, true,
        "paintshoppro", "paintshoppro5" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 5\\ImageProcessingFilter", "Directory3",
        "Paint Shop Pro 5 by JASC, 3rd path", false, false, true,
        "paintshoppro", "paintshoppro5" },
    // 6
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 6\\ImageProcessingFilter", "Directory1",
        "Paint Shop Pro 6 by JASC, 1st path", false, true, true,
        "paintshoppro", "paintshoppro6" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 6\\ImageProcessingFilter", "Directory2",
        "Paint Shop Pro 6 by JASC, 2nd path", false, false, true,
        "paintshoppro", "paintshoppro6" },
    {   HKEY_CURRENT_USER,
		"Software\\JASC\\Paint Shop Pro 6\\ImageProcessingFilter", "Directory3",
        "Paint Shop Pro 6 by JASC, 3rd path", false, false, true,
        "paintshoppro", "paintshoppro6" },
    // 7
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 7\\ImageProcessingFilter", "Directory1",
        "Paint Shop Pro 7 by JASC, 1st path", false, true, true,
        "paintshoppro", "paintshoppro7" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 7\\ImageProcessingFilter", "Directory2",
        "Paint Shop Pro 7 by JASC, 2nd path", false, false, true,
        "paintshoppro", "paintshoppro7" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 7\\ImageProcessingFilter", "Directory3",
        "Paint Shop Pro 7 by JASC, 3rd path", false, false, true,
        "paintshoppro", "paintshoppro7" },
    // 8
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 8\\ImageProcessingFilter", "Directory1",
        "Paint Shop Pro 8 by JASC, 1st path", false, true, true,
        "paintshoppro", "paintshoppro8" },
    {   HKEY_CURRENT_USER,
        "Software\\JASC\\Paint Shop Pro 8\\ImageProcessingFilter", "Directory2",
        "Paint Shop Pro 8 by JASC, 2nd path", false, false, true,
        "paintshoppro", "paintshoppro8" },
    {   HKEY_CURRENT_USER,
		"Software\\JASC\\Paint Shop Pro 8\\ImageProcessingFilter", "Directory3",
        "Paint Shop Pro 8 by JASC, 3rd path", false, false, true,
		"paintshoppro", "paintshoppro8" },
    // 9
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\0", "Dir",
        "Paint Shop Pro 9 by JASC, 1st path", false, true, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\1", "Dir",
        "Paint Shop Pro 9 by JASC, 2nd path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\2", "Dir",
        "Paint Shop Pro 9 by JASC, 3rd path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\3", "Dir",
        "Paint Shop Pro 9 by JASC, 4th path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\4", "Dir",
        "Paint Shop Pro 9 by JASC, 5th path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\5", "Dir",
        "Paint Shop Pro 9 by JASC, 6th path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\6", "Dir",
        "Paint Shop Pro 9 by JASC, 7th path", false, false, true,
        "paintshoppro", "paintshoppro9" },
    {   HKEY_CURRENT_USER,
        "Software\\Jasc\\Paint Shop Pro 9\\FileLocations\\PlugIns\\7", "Dir",
        "Paint Shop Pro 9 by JASC, 8th path", false, false, true,
        "paintshoppro", "paintshoppro9" },
	// 10 (Corel switch)
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\0", "Dir",
		"Paint Shop Pro X (10) by Corel, 1st path", false, true, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\1", "Dir",
		"Paint Shop Pro X (10) by Corel, 2nd path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\2", "Dir",
		"Paint Shop Pro X (10) by Corel, 3rd path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\3", "Dir",
		"Paint Shop Pro X (10) by Corel, 4th path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\4", "Dir",
		"Paint Shop Pro X (10) by Corel, 5th path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\5", "Dir",
		"Paint Shop Pro X (10) by Corel, 6th path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\6", "Dir",
		"Paint Shop Pro X (10) by Corel, 7th path", false, false, true,
		"paintshoppro", "paintshoppro10" },
    {   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\10\\FileLocations\\PlugIns\\7", "Dir",
		"Paint Shop Pro X (10) by Corel, 8th path", false, false, true,
		"paintshoppro", "paintshoppro10" },
	// X1 (11)
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\0", "Dir",
		"Paint Shop Pro X1 by Corel, 1st path", false, true, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\1", "Dir",
		"Paint Shop Pro X1 by Corel, 2nd path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\2", "Dir",
		"Paint Shop Pro X1 by Corel, 3rd path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\3", "Dir",
		"Paint Shop Pro X1 by Corel, 4th path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\4", "Dir",
		"Paint Shop Pro X1 by Corel, 5th path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\5", "Dir",
		"Paint Shop Pro X1 (11) by Corel, 6th path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\6", "Dir",
		"Paint Shop Pro X1 by Corel, 7th path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\11\\FileLocations\\PlugIns\\7", "Dir",
		"Paint Shop Pro X1 by Corel, 8th path", false, false, true,
		"paintshoppro", "paintshoppro11" },
	// X2 (12) - checked!
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\0", "Dir",
		"Paint Shop Pro X2 by Corel, 1st path", false, true, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\1", "Dir",
		"Paint Shop Pro X2 by Corel, 2nd path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\2", "Dir",
		"Paint Shop Pro X2 by Corel, 3rd path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\3", "Dir",
		"Paint Shop Pro X2 by Corel, 4th path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\4", "Dir",
		"Paint Shop Pro X2 by Corel, 5th path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\5", "Dir",
		"Paint Shop Pro X2 by Corel, 6th path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\6", "Dir",
		"Paint Shop Pro X2 by Corel, 7th path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\12\\FileLocations\\PlugIns\\7", "Dir",
		"Paint Shop Pro X2 by Corel, 8th path", false, false, true,
		"paintshoppro", "paintshoppro12" },
	// X3 (13) (assumed on 12!)
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\0", "Dir",
		"Paint Shop Pro X3 by Corel, 1st path", false, true, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\1", "Dir",
		"Paint Shop Pro X3 by Corel, 2nd path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\2", "Dir",
		"Paint Shop Pro X3 by Corel, 3rd path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\3", "Dir",
		"Paint Shop Pro X3 by Corel, 4th path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\4", "Dir",
		"Paint Shop Pro X3 by Corel, 5th path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\5", "Dir",
		"Paint Shop Pro X3 by Corel, 6th path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\6", "Dir",
		"Paint Shop Pro X3 by Corel, 7th path", false, false, true,
		"paintshoppro", "paintshoppro13" },
	{   HKEY_CURRENT_USER,
		"Software\\Corel\\Paint Shop Pro\\13\\FileLocations\\PlugIns\\7", "Dir",
		"Paint Shop Pro X3 by Corel, 8th path", false, false, true,
		"paintshoppro", "paintshoppro13" },
// PHOTODELUXE
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTODELUXE,
        "PhotoDeLuxe by Adobe", false, true, true,
        "photodeluxe", "photodeluxe1"   },
// PHOTODRAW
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTODRAW2K1,
        "PhotoDraw 2000 by Microsoft, 1st path", false, true, true,
        "photodraw2k", "photodraw2k1"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTODRAW2K1,
        "PhotoDraw 2000 by Microsoft, 2nd path", false, false, true,
        "photodraw2k", "photodraw2k1"   },
// PHOTOIMPACT
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP1,
        "PhotoImpact by Ulead, 1st path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP2,
        "PhotoImpact by Ulead, 2nd path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP3,
        "PhotoImpact by Ulead, 3rd path", false, false, true,
		"photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP4,
		"PhotoImpact by Ulead, 4th path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP5,
        "PhotoImpact by Ulead, 5th path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP6,
        "PhotoImpact by Ulead, 6th path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP7,
        "PhotoImpact by Ulead, 7th path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACTP8,
        "PhotoImpact by Ulead, 8th path", false, false, true,
        "photoimpact", "photoimpactall"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT5,
        "PhotoImpact 5 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact5"  },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT6,
        "PhotoImpact 6 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact6"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT7,
        "PhotoImpact 7 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact7"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT8,
        "PhotoImpact 8 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact8"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT85,
        "PhotoImpact 8.5 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact85"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT9,
        "PhotoImpact 9 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact9"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT10,
        "PhotoImpact 10 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact10"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT11,
        "PhotoImpact 11 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact11"   },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT12,
        "PhotoImpact 12 by Ulead, standard", false, true, true,
        "photoimpact", "photoimpact12"   },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT13,
		"PhotoImpact X3 by Corel, standard", false, true, true,
		"photoimpact", "photoimpact13"   },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT14,
		"PhotoImpact X4 by Corel, standard", false, true, true,
		"photoimpact", "photoimpact14"   },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOIMPACT15,
		"PhotoImpact X5 by Corel, standard", false, true, true,
		"photoimpact", "photoimpact15"   },
// PHOTOLINE
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOLINE5P1,
        "PhotoLine32 5/6 by Computerinsel, 1st path", false, true, true,
        "photoline", "photoline5"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOLINE5P2,
        "PhotoLine32 5/6 by Computerinsel, 2nd path", false, false, true,
        "photoline", "photoline5"       },
// PHOTOPAINT
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P1,
        "PhotoPaint 9 by Corel, 1st path", false, true, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P2,
        "PhotoPaint 9 by Corel, 2nd path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P3,
        "PhotoPaint 9 by Corel, 3rd path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P4,
        "PhotoPaint 9 by Corel, 4th path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P5,
        "PhotoPaint 9 by Corel, 5th path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P6,
        "PhotoPaint 9 by Corel, 6th path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P7,
        "PhotoPaint 9 by Corel, 7th path", false, false, true,
        "photopaint", "photopaint9"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT9P8,
        "PhotoPaint 9 by Corel, 8th path", false, false, true,
        "photopaint", "photopaint9"     },
    // 12
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P1,
        "PhotoPaint 12 by Corel, 1st path", false, true, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P2,
        "PhotoPaint 12 by Corel, 2nd path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P3,
        "PhotoPaint 12 by Corel, 3rd path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P4,
        "PhotoPaint 12 by Corel, 4th path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P5,
        "PhotoPaint 12 by Corel, 5th path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P6,
        "PhotoPaint 12 by Corel, 6th path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P7,
        "PhotoPaint 12 by Corel, 7th path", false, false, true,
        "photopaint", "photopaint12"     },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOPAINT12P8,
        "PhotoPaint 12 by Corel, 8th path", false, false, true,
        "photopaint", "photopaint12"     },
// PHOTOPERFECT
	{   HKEY_CURRENT_USER,
		"Software\\Arcadia Software AG\\PhotoPerfect\\Options", "Plugins",
		"PhotoPerfect 2.90 by Arcadia", false, true, true,
		"photoperfect", "photoperfect290"     },
// PHOTOPLUS
	{   HKEY_CURRENT_USER,
		"Software\\Serif\\PhotoPlus\\6.0\\Directories", "PluginRootDir",
		"PhotoPlus 6 by Serif", false, true, true,
		"photoplus", "photoplus6"     },
	{   HKEY_CURRENT_USER,
		"Software\\Serif\\PhotoPlus\\7.0\\Directories", "PluginRootDir",
		"PhotoPlus 7 by Serif", false, true, true,
        "photoplus", "photoplus7"     },
    {   HKEY_CURRENT_USER,
        "Software\\Serif\\PhotoPlus\\8.0\\Directories", "PluginRootDir",
        "PhotoPlus 8 by Serif", false, true, true,
        "photoplus", "photoplus8"     },
    {   HKEY_CURRENT_USER,
        "Software\\Serif\\PhotoPlus\\9.0\\Directories", "PluginRootDir",
        "PhotoPlus 9 by Serif", false, true, true,
        "photoplus", "photoplus9"     },
// PHOTOSHOP
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOSHOP2,
        "PhotoShop 2 by Adobe", false, true, true,
        "photoshop", "photoshop2"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOSHOP3,
        "PhotoShop 3 by Adobe", false, true, true,
        "photoshop", "photoshop3"       },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PHOTOSHOP4,
        "PhotoShop 4 by Adobe", false, true, true,
        "photoshop", "photoshop4"       },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\5.0\\PluginPath", "",
        "PhotoShop 5 by Adobe", false, true, true,
        "photoshop", "photoshop5"       },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\5.5\\PluginPath", "",
        "PhotoShop 5.5 by Adobe", false, true, true,
        "photoshop", "photoshop55"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\6.0\\PluginPath", "",
        "PhotoShop 6 by Adobe", false, true, true,
        "photoshop", "photoshop6"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\7.0\\PluginPath", "",
        "PhotoShop 7 by Adobe", false, true, true,
        "photoshop", "photoshop7"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\7.0", "PluginPath",
		"PhotoShop 7 by Adobe, additional path", false, false, true,
        "photoshop", "photoshop7"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\8.0\\PluginPath", "",
        "PhotoShop CS by Adobe", false, true, true,
        "photoshop", "photoshop8"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\8.0", "PluginPath",
		"PhotoShop CS by Adobe, additional path", false, false, true,
        "photoshop", "photoshop8"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\9.0\\PluginPath", "",
        "PhotoShop CS2 by Adobe", false, true, true,
        "photoshop", "photoshop9"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\9.0", "PluginPath",
		"PhotoShop CS2 by Adobe, additional path", false, false, true,
        "photoshop", "photoshop9"      },
	// CS3
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\10.0\\PluginPath", "",
		"PhotoShop CS3 by Adobe", false, true, true,
		"photoshop", "photoshop10"      },
	{   HKEY_CURRENT_USER, "Software\\Adobe\\Photoshop\\10.0", "PlugInDirectory",
		"PhotoShop CS3 by Adobe, additional path", false, false, true,
		"photoshop", "photoshop10" 		},
	// CS4? based on CS3/10
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\11.0\\PluginPath", "",
		"PhotoShop CS4 by Adobe", false, true, true,
		"photoshop", "photoshop11"      },
	{   HKEY_CURRENT_USER, "Software\\Adobe\\Photoshop\\11.0", "PlugInDirectory",
		"PhotoShop CS4 by Adobe, additional path", false, false, true,
		"photoshop", "photoshop11" 		},
	// CS5? based on CS3/10
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\12.0\\PluginPath", "",
		"PhotoShop CS5 by Adobe", false, true, true,
		"photoshop", "photoshop12"      },
	{   HKEY_CURRENT_USER, "Software\\Adobe\\Photoshop\\12.0", "PlugInDirectory",
		"PhotoShop CS5 by Adobe, additional path", false, false, true,
		"photoshop", "photoshop12" 		},
	// CS6? based on CS3/10
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop\\13.0\\PluginPath", "",
		"PhotoShop CS6 by Adobe", false, true, true,
		"photoshop", "photoshop13"      },
	{   HKEY_CURRENT_USER, "Software\\Adobe\\Photoshop\\13.0", "PlugInDirectory",
		"PhotoShop CS6 by Adobe, additional path", false, false, true,
		"photoshop", "photoshop13" 		},
// PhotoShop Elements
	// PSE1 are guesses based on PSE3
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\1.0\\PluginPath", "",
        "PhotoShop Elements 1 by Adobe", false, true, true,
        "photoshopelements", "photoshopelements1"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\1.0", "PlugInDirectory",
        "PhotoShop Elements 1 by Adobe, additional path", false, false, true,
        "photoshopelements", "photoshopelements1"      },
	// PSE2 are guesses based on PSE3
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\2.0\\PluginPath", "",
        "PhotoShop Elements 2 by Adobe", false, true, true,
        "photoshopelements", "photoshopelements2"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\2.0", "PlugInDirectory",
		"PhotoShop Elements 2 by Adobe, additional path", false, false, true,
        "photoshopelements", "photoshopelements2"      },
    // Elements 3
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\3.0\\PluginPath", "",
        "PhotoShop Elements 3 by Adobe", false, true, true,
        "photoshopelements", "photoshopelements3"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\3.0", "PlugInDirectory",
		"PhotoShop Elements 3 by Adobe, additional path", false, false, true,
        "photoshopelements", "photoshopelements3"      },
    // Elements 4 - guestimated from PSE3
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\4.0\\PluginPath", "",
        "PhotoShop Elements 4 by Adobe", false, true, true,
        "photoshopelements", "photoshopelements4"      },
    {   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\4.0", "PlugInDirectory",
		"PhotoShop Elements 4 by Adobe, additional path", false, false, true,
        "photoshopelements", "photoshopelements4"      },
    // Future - Elements 5 - guestimated from PSE3
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\5.0\\PluginPath", "",
		"PhotoShop Elements 5 by Adobe", false, true, true,
		"photoshopelements", "photoshopelements5"      },
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\5.0", "PlugInDirectory",
		"PhotoShop Elements 5 by Adobe, additional path", false, false, true,
		"photoshopelements", "photoshopelements5"      },
	// Future - Elements 6 - guestimated from PSE3
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\6.0\\PluginPath", "",
		"PhotoShop Elements 6 by Adobe", false, true, true,
		"photoshopelements", "photoshopelements6"      },
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\6.0", "PlugInDirectory",
		"PhotoShop Elements 6 by Adobe, additional path", false, false, true,
		"photoshopelements", "photoshopelements6"      },
	// Future - Elements 7 - guestimated from PSE3
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\7.0\\PluginPath", "",
		"PhotoShop Elements 7 by Adobe", false, true, true,
		"photoshopelements", "photoshopelements7"      },
	{   HKEY_LOCAL_MACHINE, "Software\\Adobe\\Photoshop Elements\\7.0", "PlugInDirectory",
		"PhotoShop Elements 7 by Adobe, additional path", false, false, true,
		"photoshopelements", "photoshopelements7"      },
// PICTURE PUBLISHER
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath1",
        "Picture Publisher 6 by Micrografx, 1st path", false, true, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath2",
        "Picture Publisher 6 by Micrografx, 2nd path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath3",
        "Picture Publisher 6 by Micrografx, 3rd path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath4",
        "Picture Publisher 6 by Micrografx, 4th path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath5",
        "Picture Publisher 6 by Micrografx, 5th path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath6",
        "Picture Publisher 6 by Micrografx, 6th path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath7",
        "Picture Publisher 6 by Micrografx, 7th path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\6.0\\Settings", "PluginPath8",
        "Picture Publisher 6 by Micrografx, 8th path", false, false, true,
        "picturepublisher", "picturepublisher6" },
    // 8
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath1",
        "Picture Publisher 8 by Micrografx, 1st path", false, true, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath2",
        "Picture Publisher 8 by Micrografx, 2nd path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath3",
        "Picture Publisher 8 by Micrografx, 3rd path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath4",
        "Picture Publisher 8 by Micrografx, 4th path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath5",
        "Picture Publisher 8 by Micrografx, 5th path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath6",
        "Picture Publisher 8 by Micrografx, 6th path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath7",
        "Picture Publisher 8 by Micrografx, 7th path", false, false, true,
        "picturepublisher", "picturepublisher8" },
    {   HKEY_CURRENT_USER,
        "Software\\Micrografx\\Picture Publisher\\8.0\\DirSettings", "PluginPath8",
        "Picture Publisher 8 by Micrografx, 8th path", false, false, true,
        "picturepublisher", "picturepublisher8" },
// PREMIERE
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_PREMIERE42,
        "Premiere 4.2 by Adobe", false, true, true,
        "premiere", "premiere42"            },
    {   HKEY_LOCAL_MACHINE,
        "Software\\Adobe\\Premiere\\5.0", "Plug-InsDir",
        "Premiere 5.x by Adobe", false, true, true,
        "premiere", "premiere5"             },
// QFX
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_QFX7,
        "QFX 7.0/8.0 by Ron Scott", false, true, true,
        "qfx", "qfx7"            },
// SATORI PHOTO XL
    {   HKEY_CURRENT_USER,
        "Software\\Spaceward\\Satori229\\Preferences", "PhotoshopPath",
        "Satori Photo XL 2.29 by Spaceward Graphics", false, true, true,
        "satoriphotoxl", "satoriphotoxl229" },
// ULTIMATE PAINT
    {   HKEY_CURRENT_USER, "Software\\Megalux\\UP\\Preferences", "AdobeLoc",
        "Ultimate Paint 2 by Megalux", false, true, true,
        "ultimatepaint", "ultimatepaint2"   },
// XARA XTREME
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREME,
		"Xara Xtreme 2 by Xara, main path", false, true, true,
        "xaraxtreme", "xaraxtreme2" },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP1,
        "Xara Xtreme 2 by Xara, 1st additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP2,
        "Xara Xtreme 2 by Xara, 2nd additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP3,
        "Xara Xtreme 2 by Xara, 3rd additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP4,
        "Xara Xtreme 2 by Xara, 4th additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP5,
        "Xara Xtreme 2 by Xara, 5th additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP6,
        "Xara Xtreme 2 by Xara, 6th additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP7,
        "Xara Xtreme 2 by Xara, 7th additional path", false, false, true,
        "xaraxtreme", "xaraxtreme2" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEP8,
		"Xara Xtreme 2 by Xara, 8th additional path", false, false, true,
		"xaraxtreme", "xaraxtreme2" },
// XARA XTREME PRO
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO1,
		"Xara Xtreme Pro 1 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro1" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO2,
		"Xara Xtreme Pro 2 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro2" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO3,
		"Xara Xtreme Pro 3 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro3" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO4,
		"Xara Xtreme Pro 4 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro4" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO5,
		"Xara Xtreme Pro 5 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro5" },
	{   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XARAXTREMEPRO51,
		"Xara Xtreme Pro 5.1 by Xara, main path", false, true, true,
		"xaraxtremepro", "xaraxtremepro51" },
// XRES
    {   HKEY_CURRENT_USER, TEMP_DIR, TEMP_XRES2,
        "xRes 2 by MacroMedia", false, true, true,
        "xres", "xres2"                     }
};
TReplaceFlags ALL;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
AnsiString __fastcall GetFullPath(AnsiString asDir)
{
    if(asDir != "" && asDir[asDir.Length()] != '\\')
    	asDir = asDir + "\\";
    return asDir;
}
//---------------------------------------------------------------------------
AnsiString __fastcall FindFile(AnsiString path, AnsiString pattern,
											TSearchRec srFind) {
	AnsiString result = "";

    if (GetAsyncKeyState(VK_ESCAPE)) {
    	return result;
    }

    // Find files
    if (FindFirst(GetFullPath(path) + "*", FILESCAN_FILEMASK, srFind) == 0) {
        do {
            if((srFind.Attr & faDirectory) == 0 && srFind.Name == pattern) {
                result = GetFullPath(path) + srFind.Name;
                break;
            }
            else if(srFind.Name != "." && srFind.Name != "..") {
            	AnsiString subdir = FindFile(GetFullPath(path) + srFind.Name
                							+ "\\", pattern, srFind);
                if (!subdir.IsEmpty()) {
                	result = subdir;
                	break;
                }
            }
        } while(FindNext(srFind) == 0);
    }

    FindClose(srFind);

    return result;
}
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    ALL << rfReplaceAll;

    Application->OnHint = ShowStatusHint;

    // start
	AnsiString asStart = GetIni("messages", "start");
    if(!asStart.IsEmpty())
        Application->MessageBox(asStart.c_str(),
                                LoadStr( RES_MB_COPYRIGHT ).c_str(),
                                MB_ICONINFORMATION|MB_OK);

    SetupWindow();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	bool cont = true;
    const AnsiString asAgreement = GetIni("messages", "agreement");
    if(!asAgreement.IsEmpty()) {
		const bool bAgree = GetIni("messages", "agree") == "1" ? true : false;
		AnsiString f = ExtractFilePath(Application->ExeName) + asAgreement;
		AgreementForm->Memo->Lines->LoadFromFile(f);
		AgreementForm->AgreeYes->Checked = bAgree;
        AgreementForm->AgreeNo->Checked  = !bAgree;
        if(AgreementForm->ShowModal() == mrCancel) {
			cont = false;
            Application->Terminate();
        }
	}

	Copyright->Caption = "© " + AnsiString(YearOf(Now())) + " VanDerLee";

    if(cont) {
		if(GetIni("options", "autoscan") == "1")
	        ScanForFiles();
    	DetectAll();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetupWindow(void)
{
	if (int w = GetIni("presentation", "width").ToIntDef(0) > MainForm->Constraints->MinWidth) {
    	MainForm->Width = w;
    }
	if (int w = GetIni("presentation", "height").ToIntDef(0) > MainForm->Constraints->MinHeight) {
    	MainForm->Height = w;
    }
    MainForm->Caption = GetIni("presentation", "caption");
    AnsiString bitmap = GetIni("presentation", "bitmap");
    if (FileExists(bitmap)) {
	    Image->Picture->LoadFromFile(ExtractFilePath(Application->ExeName) + bitmap);
    }
    AnsiString bitmaplink = GetIni("presentation", "bitmaplink");
    if (!bitmaplink.IsEmpty()) {
        ImagePanel->Hint = bitmaplink;
        ImagePanel->ShowHint = true;
//        ImagePanel->BevelOuter = bvRaised;
//        ImagePanel->BevelInner = bvRaised;
    }
    Title->Caption    = GetIni("presentation", "title");
    Version->Caption  = GetIni("presentation", "version");
    Text->Caption     = StringReplace(Text->Caption, "#t", Title->Caption, ALL);

    // Process the "scan" button
    if(GetIni("presentation", "scan.visible") != "1")
        Rescan->Visible = false;
    else {
        Rescan->Flat        = GetIni("presentation", "scan.flat").ToIntDef(1);
        Rescan->Caption     = GetIni("presentation", "scan.caption");
    }

    // Process the "browse" button
    Browse->Flat        = GetIni("presentation", "browse.flat").ToIntDef(1);
    Browse->Caption     = GetIni("presentation", "browse.caption");

    // Options
    asSubDir          = GetIni("options", "subdir");

    Custom->Text   = GetIni("options", "custom");
    if(Custom->Text.IsEmpty())
        Custom->Text = GetRegistryString(HKEY_LOCAL_MACHINE,
                                "Software\\Microsoft\\Windows\\CurrentVersion",
                                "ProgramFilesPath");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    // close
    AnsiString asStart = GetIni("messages", "close");
    if(!asStart.IsEmpty())
        Application->MessageBox(asStart.c_str(),
                                LoadStr( RES_MB_COPYRIGHT ).c_str(),
                                MB_ICONINFORMATION|MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowStatusHint(TObject *Sender)
{
    Status->SimpleText = Application->Hint;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectedMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    //int Item = Y / Detected->ItemHeight;
    int Item = Detected->ItemAtPos(Point(X, Y), true);
    if(Item >= 0) {
        //   Detected->Hint = Detected->Items->Strings[Item];
        unsigned int iApp = 0;
        while(iApp           <  ARRAYSIZE(App)) {
            if(AnsiString(App[iApp].Info) == Detected->Items->Strings[Item]) {
                Detected->Hint = GetRegistryString( App[iApp].Root,
                                    AnsiString(App[iApp].Key),
                                    AnsiString(App[iApp].Name));
            }
            ++iApp;
        }
    }
    else
        Detected->Hint = LoadStr(RES_DET_HINT);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetIni(AnsiString asSection, AnsiString asKey)
{
	AnsiString f = ExtractFilePath(Application->ExeName) + AnsiString(INIFILE);
	TIniFile *ifSetup = new TIniFile(f);
    AnsiString asResult = ifSetup->ReadString(asSection, asKey, "");
    delete ifSetup;
    return asResult;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetIniDefault(AnsiString asSection,
        AnsiString asKey, AnsiString def)
{
    TIniFile *ifSetup = new TIniFile(ExtractFilePath(Application->ExeName)
                                    + AnsiString(INIFILE));
    AnsiString asResult = ifSetup->ReadString(asSection, asKey, def);
    delete ifSetup;
    return asResult;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetRegistryString(HKEY asRootKey,
					AnsiString asDir, AnsiString asKey)
{
    AnsiString asValue  = "";
	TRegistry *Registry = new TRegistry;

    Registry->RootKey   = asRootKey;
    Registry->Access	= KEY_READ;
	if(Registry->OpenKey(asDir, false) && Registry->ValueExists(asKey))
        switch(Registry->GetDataType(asKey)) {
            case rdString:  asValue = Registry->ReadString(asKey);
                            break;
            case rdBinary:  char Buffer[MAXPATH];
                            Registry->ReadBinaryData(asKey, Buffer,
                                            Registry->GetDataSize(asKey));
                            Buffer[Registry->GetDataSize(asKey)] = 0;
                            asValue = AnsiString(Buffer);
                            break;
            default:        break;
        }

    delete Registry;
    return asValue;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteAllTemp(void)
{
    TRegistry *Registry = new TRegistry;
    Registry->DeleteKey(TEMP_DIR);

    delete Registry;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseClick(TObject *Sender)
{
    char WDir[MAX_PATH];
  	memset(WDir, 0, MAX_PATH);
   	char FolderName[MAX_PATH];
  	LPITEMIDLIST ItemID;

    BROWSEINFO bi;
  	memset(&bi,  0, sizeof(BROWSEINFO));
  	bi.hwndOwner        = Handle;
  	bi.pszDisplayName   = FolderName;
  	bi.lpszTitle        = LoadStr(RES_BROWSE_DIR).c_str();
  	ItemID              = SHBrowseForFolder(&bi);
  	SHGetPathFromIDList(ItemID, WDir);
  	GlobalFreePtr(ItemID);

    if(AnsiString(WDir) != "") {
        Custom->Text        = AnsiString(WDir);
        DoCustom->Checked   = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if(Application->MessageBox(LoadStr(RES_MB_CLOSE_B).c_str(),
                               LoadStr(RES_MB_CLOSE_C).c_str(),
                               MB_ICONWARNING|MB_YESNO) == IDYES) {
        CanClose = true;
        DeleteAllTemp();
    }
    else
        CanClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InstallClick(TObject *Sender)
{
    if(DoCustom->Checked
    && !DirectoryExists(Custom->Text)) {
            if(Application->MessageBox(LoadStr(RES_CDIR_NOT_EXIST).c_str(),
                                       LoadStr(RES_WARNING).c_str(),
                                       MB_ICONWARNING|MB_YESNO) == mbYes)
                DoCustom->Checked = false;
            else
                return;
        }

    // Calculate total amount of apps
	unsigned int iApp;
    int iTotal = 0;
    for(iApp = 0; iApp < (unsigned int)Detected->Items->Count; ++iApp)
        if(Detected->Checked[iApp])
            ++iTotal;
    if(DoCustom->Checked)
        ++iTotal;

    if(iTotal > 0)
        ProgressForm->AppBar->Max = iTotal - 1;
    else {
        Application->MessageBox(LoadStr(RES_NO_FOLDERS_SEL).c_str(),
                                LoadStr(RES_ERROR).c_str(),MB_ICONERROR|MB_OK);
        return;
    }

    ProgressForm->Show();
    AnsiString asInfo;

    // Handle per application
	iApp = 0;
    while(iApp                      <  ARRAYSIZE(App)
       && ProgressForm->ModalResult == mrNone) {
        asInfo = AnsiString(App[iApp].Info);
        if(App[iApp].Detected
        && Detected->Checked[Detected->Items->IndexOf(asInfo)]) {
    		ProgressForm->App->Caption = asInfo
                                           + " (" + AnsiString(iApp + 1)
                                           + "/" + AnsiString(iTotal) + ")";
            ProgressForm->AppBar->Position = iApp;
            ProgressForm->Refresh();

            CopyFiles(iApp);
        }
        ++iApp;
    }

    // Custom path
    if(DoCustom->Checked) {
        ProgressForm->App->Caption = GetFullPath(Custom->Text)
                                   + " (" + AnsiString(iTotal)
                                   + "/" + AnsiString(iTotal) + ")";
        ProgressForm->AppBar->Position = iApp;
        ProgressForm->Refresh();

        CopyFiles(-1);
    }

    ProgressForm->Hide();
    if(Application->MessageBox(LoadStr(RES_COMPLETE_EXIT).c_str(),
                               LoadStr(RES_COMPLETED).c_str(),
                               MB_ICONINFORMATION|MB_YESNO) == IDYES)
        Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CopyFiles(int iApp)
{
    AnsiString asDest;
	LPVOID lpMsgBuf;
    TStringList* files = new TStringList();

    // Determine source directory
    AnsiString srcPath = ExtractFilePath(Application->ExeName);

    // Attain list of all files!
    TIniFile *ifSetup = new TIniFile(srcPath + AnsiString(INIFILE));
    TStringList *keys = new TStringList();
	ifSetup->ReadSection("files", keys);
    const int count = keys->Count;
    delete ifSetup;

    for (int f = 0; f < count; ++f) {
    	AnsiString wildcard = GetIni("files", keys->Strings[f]);
		int last = wildcard.LastDelimiter("\\");
        AnsiString path = wildcard.SubString(1, last);
        AnsiString file = wildcard.Delete(1, last);

	    // Find files
		TSearchRec srFind;
    	if (FindFirst(srcPath + path + file, FILESCAN_FILEMASK, srFind) == 0)
        	do {
            	if((srFind.Attr & faDirectory) == 0) {
            		files->Add(path + srFind.Name);
                }
	        } while(FindNext(srFind) == 0);

	    FindClose(srFind);
    }
    delete keys;

    // Set progress window
    ProgressForm->FileBar->Max = files->Count;

    // Determine destination directory
    if (iApp < 0) {
        asDest = GetFullPath(Custom->Text) + asSubDir + "\\";
    } else {
        asDest = GetRegistryString( App[iApp].Root,
                                    AnsiString(App[iApp].Key),
                                    AnsiString(App[iApp].Name));
        if (App[iApp].Folder) {
            asDest = GetFullPath(asDest) + asSubDir + "\\";
        }
    }

    // Create destination directory if it doesn't already exist
    if(!DirectoryExists(ExtractFileDir(asDest))) {
        if(!CreateDir(ExtractFileDir(asDest))) {
            Application->MessageBox(
		                StringReplace(LoadStr(RES_SUBDIR_CREATE), "#d"
        		                    ,ExtractFileDir(asDest),ALL).c_str()
			                		,LoadStr(RES_ERROR).c_str()
					                ,MB_ICONERROR|MB_OK);
        }
    }

    // Copy files
    for (int f = 0; f < files->Count; ++f) {
        AnsiString asFile = files->Strings[f];

        ProgressForm->File->Caption = asFile
                                   + " (" + AnsiString(f + 1)
                                   + "/" + AnsiString(count) + ")";
        ProgressForm->FileBar->Position = f;
        ProgressForm->Refresh();

        // create subdir
    	AnsiString newDir = ExtractFileDir(asDest + asFile);
        if (!newDir.IsEmpty()) {
        	if (!ForceDirectories(newDir)) {
       		    Application->MessageBox(
		                StringReplace(LoadStr(RES_SUBDIR_CREATE), "#d"
   		        		            ,newDir, ALL).c_str()
	    		            		,LoadStr(RES_ERROR).c_str()
					                ,MB_ICONERROR|MB_OK);
    		}
		}

        if (!CopyFile(AnsiString(srcPath + asFile).c_str(),
                     AnsiString(asDest + asFile).c_str(), false)) {
			if (FormatMessage(
    				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        	        NULL, GetLastError(),
    	    		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
	    	    	(LPTSTR) &lpMsgBuf, 0, NULL ) != 0 ) {
                AnsiString message = LoadStr(RES_COPY_ERROR);
                message =  StringReplace(message, "#f", asFile,ALL);
                message =  StringReplace(message, "#e", AnsiString((LPTSTR)lpMsgBuf), ALL);
                Application->MessageBox(message.c_str(), LoadStr(RES_ERROR).c_str()
                                        ,MB_ICONERROR|MB_OK);
            } else {
                AnsiString message = LoadStr(RES_COPY_ERROR_NR);
                message =  StringReplace(message, "#f", asFile,ALL);
                message =  StringReplace(message, "#e", AnsiString(GetLastError()),
                						ALL);
                Application->MessageBox(message.c_str(), LoadStr(RES_ERROR).c_str(),
                						MB_ICONERROR|MB_OK);
            }

			LocalFree(lpMsgBuf);
        }
    }

    delete files;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::CheckEnabled(int iApp)
{
    AnsiString  asResult = "1";

    asResult = GetIni("enabled", App[iApp].Enabled);
    if(asResult.IsEmpty()) {
        asResult = GetIni("enabled", App[iApp].ParentEnabled);
        if(asResult.IsEmpty()) {
            asResult = GetIni("enabled", "all");
            if(asResult.IsEmpty())
                asResult = "1";
        }
    }

    return (asResult != "0");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetTemp(AnsiString asKey, AnsiString asValue)
{
	TRegistry *Registry = new TRegistry;

    Registry->RootKey   = HKEY_CURRENT_USER;
	if(Registry->OpenKey(TEMP_DIR, true))
  	    Registry->WriteString(asKey, asValue);

    delete Registry;
}
//---------------------------------------------------------------------------



/////////////////////////////////////////////////////////////////////////////
//  GENERIC DETECTION
/////////////////////////////////////////////////////////////////////////////
void __fastcall TMainForm::DetectAll(void)
{
    // Custom scanning
    DetectFreehand8();
    DetectPhotoline5();
    DetectPhotodraw2000();
    DetectPhotoPaint9();
    DetectPhotoPaint12();
    DetectPhotoImpact();
    DetectPainter();
    DetectFireworks();
    DetectCanvas();
    DetectXaraXtreme();

    // Add all detected apps to the list
    Detected->Clear();
    for(unsigned int iLoop = 0; iLoop < ARRAYSIZE(App); ++iLoop)
        DetectApplication(iLoop);
//    Detected->Sorted        = true;
// already sorted!

    // Set custom directory when nothing autodetected
    if(Detected->Items->Count == 0)
        DoCustom->Checked   = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectApplication(int iApp)
{
    if(CheckEnabled(iApp) == true)
        if(!GetRegistryString(App[iApp].Root, AnsiString(App[iApp].Key),
                              AnsiString(App[iApp].Name)).IsEmpty()) {
            App[iApp].Detected = true;
            Detected->Items->Append(AnsiString(App[iApp].Info));
            if(GetIni("options", "autoselect") != "0")
                Detected->Checked[Detected->Items->Count - 1]
                										= App[iApp].Default;
        }
}
//---------------------------------------------------------------------------



/////////////////////////////////////////////////////////////////////////////
//  APPLICATION SPECIFIC DETECTION ROUTINES
/////////////////////////////////////////////////////////////////////////////
void __fastcall TMainForm::DetectFreehand8(void)
{
    AnsiString asPath   = GetRegistryString(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Macromedia\\FreeHand\\8\\Installation", "InstallPath");
    AnsiString asDir    = GetRegistryString(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Macromedia\\FreeHand\\8\\English", "XtrasDir");

    if(!asPath.IsEmpty() && !asDir.IsEmpty())
        SetTemp(TEMP_FREEHAND8, GetFullPath(asPath) + asDir);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPhotoline5(void)
{
    AnsiString asPath   = GetRegistryString(HKEY_CURRENT_USER,
        "Software\\Computerinsel\\PhotoLine\\Settings", "PlugInPath");
    if(!asPath.IsEmpty())
        asPath = asPath.SubString(3,asPath.Length() - 2);
    if(!asPath.IsEmpty())
        SetTemp(TEMP_PHOTOLINE5P1, asPath);

    asPath   = GetRegistryString(HKEY_CURRENT_USER,
        "Software\\Computerinsel\\PhotoLine\\Settings", "PlugInPath2");
    if(!asPath.IsEmpty())
        asPath = asPath.SubString(3,asPath.Length() - 2);
    if(!asPath.IsEmpty())
        SetTemp(TEMP_PHOTOLINE5P2, asPath);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPhotodraw2000(void)
{
    AnsiString asPath   = GetRegistryString(HKEY_CURRENT_USER,
        "Software\\Microsoft\\PhotoDraw\\1.0", "InstallDest");
    if(!asPath.IsEmpty())
        SetTemp(TEMP_PHOTODRAW2K1, GetFullPath(asPath) + "PhotoDraw\\PlugIns");

    asPath   			= GetRegistryString(HKEY_CURRENT_USER,
      "Software\\Microsoft\\PhotoDraw\\1.0\\Settings", "AdditionalPlugInPath");
    if(!asPath.IsEmpty())
        SetTemp(TEMP_PHOTODRAW2K2, asPath);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPhotoPaint9(void)
{
    AnsiString asPath = GetRegistryString(HKEY_CURRENT_USER,
        		"Software\\Corel\\Corel PHOTO-PAINT\\9", "LastWorkspaceUsed");
    if (asPath.IsEmpty())
    	return;

    asPath = asPath.SubString(1, asPath.Length() - 4);

    TIniFile *ifFile = new TIniFile(GetFullPath(asPath) + "photopnt.ini");
    for(int iPath = 1; iPath <= 8; ++iPath) {
    	const AnsiString asResult = ifFile->ReadString("PluginFilters",
        										"Dirs" + AnsiString(iPath), "");
        if(!asResult.IsEmpty())
            SetTemp(TEMP_PHOTOPAINT9Pn + AnsiString(iPath),
                  	asResult.SubString(1, asPath.Length() - 3));
    }
    delete ifFile;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPhotoPaint12(void)
{
    AnsiString asPath = GetRegistryString(HKEY_CURRENT_USER,
        		"Software\\Corel\\CorelDraw\\12.0\\CorelPHOTO-PAINT", "LastWorkspaceUsed");
    if (asPath.IsEmpty())
    	return;

    asPath = asPath.SubString(1, asPath.Length() - 4);

    TIniFile *ifFile = new TIniFile(GetFullPath(asPath) + "CorelPP.ini");
    for(int i = 1; i <= 8; ++i) {
    	const AnsiString asResult = ifFile->ReadString("PluginFilters",
        										"Dirs" + AnsiString(i), "");
        if(!asResult.IsEmpty()) {
            SetTemp(TEMP_PHOTOPAINT12Pn + AnsiString(i),
                  	asResult.SubString(1, asResult.Length() - 3));
        }
    }
    delete ifFile;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPhotoImpact(void)
{
	// 5 - 12
	for (int i = 5; i <= 12; ++i) {
		AnsiString path = GetRegistryString(HKEY_LOCAL_MACHINE,
			"Software\\Ulead Systems\\Ulead PhotoImpact\\" + AnsiString(i) + ".0\\installer", "Path");
		if(!path.IsEmpty())
			SetTemp(TEMP_PHOTOIMPACTn + AnsiString(i), path + "\\plugin");
	}

	// 13 - 15
	for (int i = 13; i <= 15; ++i) {
		AnsiString path = GetRegistryString(HKEY_LOCAL_MACHINE,
			"Software\\Ulead Systems\\Ulead PhotoImpact\\" + AnsiString(i) + ".0\\installer", "Path");
		if(!path.IsEmpty())
			SetTemp(TEMP_PHOTOIMPACTn + AnsiString(i), path + "plugin");
	}

    // 8.5
    AnsiString path = GetRegistryString(HKEY_LOCAL_MACHINE,
		"Software\\Ulead Systems\\Ulead PhotoImpact\\8.5\\installer", "Path");
    if(!path.IsEmpty())
		SetTemp(TEMP_PHOTOIMPACT85, path + "\\plugin");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectPainter(void)
{
	// 9 - checked and tested
    AnsiString asPath   = GetRegistryString(HKEY_LOCAL_MACHINE,
        "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Painter IX.exe", "Path");
    if(!asPath.IsEmpty())
		SetTemp(TEMP_PAINTER9, asPath + "Plugins");

	// 10? -> Guestimated... most likely incorrect!
	asPath   = GetRegistryString(HKEY_LOCAL_MACHINE,
		"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Painter 10.exe", "Path");
	if(!asPath.IsEmpty())
		SetTemp(TEMP_PAINTER10, asPath + "Plugins");
	asPath   = GetRegistryString(HKEY_LOCAL_MACHINE,
		"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Painter X.exe", "Path");
	if(!asPath.IsEmpty())
		SetTemp(TEMP_PAINTER10, asPath + "Plugins");

	// 11 (XI) -> Checked, but is this reliable?
	asPath = GetRegistryString(HKEY_LOCAL_MACHINE,
		"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Sketch Pad.exe", "Path");
	if(!asPath.IsEmpty())
		SetTemp(TEMP_PAINTER11, asPath + "Support Files\\Plugins");
}
//---------------------------------------------------------------------------
AnsiString __fastcall ParseFireworks(AnsiString filename) {
	AnsiString result = "";
	bool use = false;

	TStringList *xml = new TStringList();
    xml->LoadFromFile(filename);
    for (int i = 0; i < xml->Count; ++i) {
    	if (xml->Strings[i].Trim() == "<key>UseExtraPhotoshopPluginsDir</key>"
    	  && xml->Strings[i + 1].Trim() == "<bool>true</bool>") {
          	use = true;
    	}
    	if (xml->Strings[i].Trim() == "<key>ExtraPhotoshopPluginsDir</key>") {
        	AnsiString value = xml->Strings[i + 1];
            int begin = value.Pos("<string>");
            int end = value.Pos("</string>");
            result = value.SubString(begin + 8, end - (begin + 8));
    	}
	}

    if (use)
    	return result;

   	return AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectFireworks(void)
{
	// detect versions 8 - 1
	for (int i = 8; i >= 1; --i) {
		AnsiString installPath   = GetRegistryString(HKEY_LOCAL_MACHINE,
        	"Software\\Macromedia\\Fireworks\\" + AnsiString(i) + "\\Installation", "InstallPath");
    	if (!installPath.IsEmpty()) {
        	// get AppData path
			AnsiString appData   = GetRegistryString(HKEY_CURRENT_USER,
            	"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", "AppData");
            if (!appData.IsEmpty()) {
            	// find "Fireworks # Preferences.txt" file
                AnsiString file = FindFile(appData + "\\Macromedia\\Fireworks " + AnsiString(i),
	                   	"Fireworks " + AnsiString(i) + " Preferences.txt", TSearchRec());
	        	// set
                AnsiString plugins = ParseFireworks(file);
                if (!plugins.IsEmpty()) {
	    	    	SetTemp(TEMP_FIREWORKSn + AnsiString(i), plugins);
                }
            }

            break;
        }
    }
}
//---------------------------------------------------------------------------
AnsiString __fastcall ParseCanvas(AnsiString filename) {
	TStringList *lines = new TStringList();
    lines->LoadFromFile(filename);
    for (int i = 0; i < lines->Count; ++i) {
		if (lines->Strings[i].SubString(2,16) == "PPRF:plugInPath1") {
			AnsiString line = lines->Strings[i];
			int comma = line.Pos(",");
			int close = line.Pos(")");
			int length = line.SubString(comma + 1, (close - comma) - 1).ToInt();
			int quote = line.Pos("\"");
			return line.SubString(quote + 1, length);
		}
	}

	for (int i = 0; i < lines->Count; ++i) {
		if (lines->Strings[i].SubString(2,15) == "PPRF:plugInPath") {
			AnsiString line = lines->Strings[i];
			int comma = line.Pos(",");
			int close = line.Pos(")");
			int length = line.SubString(comma + 1, (close - comma) - 1).ToInt();
			int quote = line.Pos("\"");
			return line.SubString(quote + 1, length);
		}
	}

	return "";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectCanvas(void)
{
	AnsiString appData   = GetRegistryString(HKEY_CURRENT_USER,
		"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders", "AppData");
	if (!appData.IsEmpty()) {
		AnsiString path;

		// detect version 9
		path = appData + "\\Deneba\\Canvas9\\CVAppData.set";
		if (FileExists(path)) {
			AnsiString plugins = ParseCanvas(path);
			if (!plugins.IsEmpty()) {
				SetTemp(TEMP_CANVAS9, plugins);
			}
		}

		// detect version 10
		path = appData + "\\ACD Systems\\Canvas X\\CVAppData.set";
		if (FileExists(path)) {
			AnsiString plugins = ParseCanvas(path);
			if (!plugins.IsEmpty()) {
				SetTemp(TEMP_CANVAS10, plugins);
			}
		}

		// detect version 11
		path = appData + "\\ACD Systems\\Canvas 11\\CVAppData.set";
		if (FileExists(path)) {
			AnsiString plugins = ParseCanvas(path);
			if (!plugins.IsEmpty()) {
				SetTemp(TEMP_CANVAS11, plugins);
			}
		}

		// detect version 12
		path = appData + "\\ACD Systems\\Canvas 12\\CVAppData.set";
		if (FileExists(path)) {
			AnsiString plugins = ParseCanvas(path);
			if (!plugins.IsEmpty()) {
				SetTemp(TEMP_CANVAS12, plugins);
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetectXaraXtreme(void)
{
	// Xtreme
	AnsiString rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\Xara Xtreme", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREME, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 1
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\1", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO1, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 2
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\2", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO2, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 3
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\3", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO3, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 4
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\4", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO4, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 5
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\5", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO5, rootDir + "Xara Picture Editor\\PSplug-ins");
	}

	// Xtreme Pro 5.1
	rootDir   = GetRegistryString(HKEY_LOCAL_MACHINE, "Software\\Xara\\XtremePro\\5.1", "XaraX Root Dir");
	if (!rootDir.IsEmpty()) {
		SetTemp(TEMP_XARAXTREMEPRO51, rootDir + "Xara Picture Editor\\PSplug-ins");
	}
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
//  FILE SCANNING SYSTEM!
/////////////////////////////////////////////////////////////////////////////
void __fastcall TMainForm::ScanForFiles(void)
{
	bool rc = true;

    ScanProgressForm->Show();

    TSearchRec srFind;
    char cDrive[4] = FIRST_DRIVE;
    do {
        if(GetDriveType(cDrive) == DRIVE_FIXED)
            rc = FileScan(cDrive, 0, srFind);
        ++cDrive[0];
    } while(rc && cDrive[0] <= LAST_DRIVE);

    ScanProgressForm->Hide();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::FileScan(AnsiString asPath, int iDepth,
									TSearchRec srFind)
{
	bool rc = true;

    if(GetAsyncKeyState(VK_ESCAPE))
    	return false;

    if(iDepth < 3) {
        ScanProgressForm->Drive->Caption = asPath;
        ScanProgressForm->Refresh();
    }

    // Find files
    if(FindFirst(asPath + "*", FILESCAN_FILEMASK, srFind) == 0)
        do {
            if((srFind.Attr & faDirectory) == 0)
                CheckFile(GetFullPath(asPath), srFind.Name);
            else
                if(srFind.Name != "." && srFind.Name != "..")
                    rc = FileScan(asPath + srFind.Name + "\\", iDepth + 1,
                    				srFind);
        } while(rc && FindNext(srFind) == 0);

    FindClose(srFind);

    return rc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckFile(AnsiString asPath, AnsiString asFile)
{
    static bool bIEP4    	= false;
	const AnsiString Ext 	= ExtractFileExt(asFile).LowerCase();
    const AnsiString File	= asFile.LowerCase();

    // INI files
    if(Ext == ".ini") {
		if(File == "pd.ini") {							// Adobe PhotoDeLuxe 1
	        TIniFile *ifFile    = new TIniFile(asPath + asFile);
    	    AnsiString asResult = ifFile->ReadString("PhotoDeluxe 1.0",
        	                                         "PLUGINDIRECTORY", "");
    	    if(!asResult.IsEmpty())
	            SetTemp(TEMP_PHOTODELUXE, asResult);
	        delete ifFile;
    	}
    	else if(File == "photoshp.ini") {			 	// Adobe PhotoShop 2.x
        	TIniFile *ifFile    = new TIniFile(asPath + asFile);
	        const AnsiString asResult = ifFile->ReadString("Photoshop",
        												"PlugInDirectory", "");
    	    if(!asResult.IsEmpty())
        	    SetTemp(TEMP_PHOTOSHOP2, asResult);
	        delete ifFile;
    	}
	    else if(File == "photos30.ini") {				// Adobe PhotoShop 3.x
    	    TIniFile *ifFile    = new TIniFile(asPath + asFile);
        	const AnsiString asResult = ifFile->ReadString("Photoshop",
        												"PlugInDirectory", "");
	        if(!asResult.IsEmpty())
    	        SetTemp(TEMP_PHOTOSHOP3, asResult);
        	delete ifFile;
	    }
	    else if(File == "photos40.ini") {		  		// Adobe PhotoShop 4.x
    	    TIniFile *ifFile    = new TIniFile(asPath + asFile);
        	const AnsiString asResult = ifFile->ReadString("Photoshop",
        												"PlugInDirectory", "");
	        if(!asResult.IsEmpty())
    	        SetTemp(TEMP_PHOTOSHOP4, asResult);
        	delete ifFile;
	    }
    	else if(File == "iep.ini") {
    	    TIniFile *ifFile = new TIniFile(asPath + asFile);
	        AnsiString asResult = ifFile->ReadString("Settings","Plugin Path",
            											"");
        	if(!asResult.IsEmpty()) {
    	        SetTemp(TEMP_IMAGEEXPLORERPRO4, asResult);
	            bIEP4   = true;
        	}
    	    delete ifFile;
	    }
	    else if(File == "xres.ini") {			 		// MacroMedia xRes 2
    	    TIniFile *ifFile    = new TIniFile(asPath + asFile);
        	AnsiString asResult = ifFile->ReadString("Main", "PluginDirectory",
            											"");
	        if(!asResult.IsEmpty())
    	        SetTemp(TEMP_XRES2, asResult);
        	delete ifFile;
	    }
	    else if(File == "ulead32.ini") {		   		// ULead PhotoImpact
	        TIniFile *ifFile = new TIniFile(asPath + asFile);
    	    for(int iPath = 1; iPath <= 8; ++iPath)
        	    if(ifFile->ReadBool("PLUG IN", "UseDir" + AnsiString(iPath),
                					false)) {
            	    AnsiString asResult = ifFile->ReadString("PLUG IN",
                                        "PLUGINDIR" + AnsiString(iPath), "");
                	if(!asResult.IsEmpty())
                    	SetTemp(TEMP_PHOTOIMPACTPn + AnsiString(iPath),
                        		asResult);
	            }
    	    delete ifFile;
	    }
		else if(File == "qfxwin.ini") {		   			// QFX 7.0 / 8.0
	        TStringList *slFile = new TStringList();
    	    slFile->LoadFromFile(asPath + asFile);
			int iLine = 0;
			while(iLine < slFile->Count
 			   && slFile->Strings[iLine].Pos("PluginFilePath,") != 1)
    			++iLine;
    	    if(iLine < slFile->Count) {		        			// Found?
	    		AnsiString asResult = slFile->Strings[iLine].Delete(1, 15);
            	asResult = asResult.SubString(1, asResult.Pos(";") - 1).Trim();
	            asResult = asResult.SubString(2, asResult.Length() - 2);
    		    SetTemp(TEMP_QFX7, asResult);
        	}
	        delete slFile;
    	}
    }
    // EXE files
    else if(Ext == ".exe") {
		if(File == "premiere.exe"						// Adobe Premiere 4.2
		&& DirectoryExists(asPath + "plugins"))
           	SetTemp(TEMP_PREMIERE42, asPath + "plugins\\");
	    else if(File == "afterfx.exe"	   				// AfterFX 4.1
        && DirectoryExists(asPath + "plug-ins"))
            SetTemp(TEMP_AFTERFX41, asPath + "plug-ins\\");
 	   	else if(File == "image explorer pro.exe"		// Image Explorer Pro 4
             && !bIEP4)
            SetTemp(TEMP_IMAGEEXPLORERPRO4, asPath + asFile + "\\Plugins");
	    else if(File == "darkroom.exe"	// MicroFrontier Digital Darkroom 1.2
             && DirectoryExists(asPath + "DDStuff\\Plugins"))
            SetTemp(TEMP_DIGITALDARKROOM, asPath + "DDStuff\\Plugins\\");
		else if(File == "imagen.exe"   				   	// PS imageN 1.2
        && FileExists(asPath + "plugdirs.cfg")) {
            TStringList *slFile = new TStringList();
            slFile->LoadFromFile(asPath + "plugdirs.cfg");
            for(int iPath = 0; iPath < min(8, slFile->Count); ++iPath)
                if(!slFile->Strings[iPath].IsEmpty())
                    SetTemp(TEMP_IMAGENPn + AnsiString(iPath + 1),
                            slFile->Strings[iPath]);
            delete slFile;
        }
	}
    else if(File == "aiprefs") {   						// Adobe Illustrator 7
        bool bSectionFound  = false;
        TStringList *slFile = new TStringList();
        slFile->LoadFromFile(asPath + asFile);
        for(int iLine = 0; iLine < slFile->Count; ++iLine) {
            if(slFile->Strings[iLine].SubString(1, 10) == "/plugins {" )
                bSectionFound = true;
            if((slFile->Strings[iLine].SubString(1, 8) == "\t/name (")
            && bSectionFound) {
                AnsiString asPlugPath = slFile->Strings[iLine].Delete(1, 8);
                asPlugPath = asPlugPath.Delete(asPlugPath.Length(), 1);
                while(asPlugPath.Pos("\\\\") != 0)
                    asPlugPath = asPlugPath.Delete(asPlugPath.Pos("\\\\"), 1);
                SetTemp(TEMP_ILLUSTRATOR7, asPlugPath);
                iLine = slFile->Count;
            }
        }
        delete slFile;
    }
    else if(File.SubString(1, 9) == "fireworks"			// MacroMedia FireWorks
    	 && Ext == ".txt") {
        TStringList *slFile = new TStringList();
        slFile->LoadFromFile(asPath + asFile);
        for(int iLine = 0; iLine < slFile->Count; ++iLine)
            if(slFile->Strings[iLine].SubString(1, 26)
                == "(ExtraPhotoshopPluginsDir)") {
                AnsiString asPlugPath = slFile->Strings[iLine].Delete(1, 28);
                asPlugPath = asPlugPath.Delete(asPlugPath.Length(), 1);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\1\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS1, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\2\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS2, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\3\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS3, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\4\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS4, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\5\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS5, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\6\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS6, asPlugPath);
                if(GetFullPath(GetRegistryString(HKEY_LOCAL_MACHINE
                    , "Software\\Macromedia\\Fireworks\\7\\Installation"
                    , "InstallPath")) == asPath)
                    SetTemp(TEMP_FIREWORKS7, asPlugPath);
                iLine = slFile->Count;
            }
        delete slFile;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RescanClick(TObject *Sender)
{
    ScanForFiles();
    DetectAll();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CopyrightClick(TObject *Sender)
{
	ShellExecute(Handle,
    			 NULL,
                 "http://www.vanderlee.com/",
              	 NULL,
                 NULL,
                 NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ImageClick(TObject *Sender)
{       
    AnsiString bitmaplink = GetIni("presentation", "bitmaplink");

    if (!bitmaplink.IsEmpty()) {
        char* p_bitmaplink = new char[bitmaplink.Length() + 1];
        strcpy(p_bitmaplink, bitmaplink.c_str());

    	ShellExecute(Handle,
        			 NULL,
                     p_bitmaplink,
                  	 NULL,
                     NULL,
                     NULL);

        delete[] p_bitmaplink;
    }
}
//---------------------------------------------------------------------------

