COMMENT=		Text Editor Product Line

GNOME_PROJECT=		tepl
GNOME_VERSION=		6.4.0

CATEGORIES=		devel

SHARED_LIBS += tepl-6                    1.0 # 2

# LGPLv2.1
PERMIT_PACKAGE=		Yes

WANTLIB += amtk-5 cairo gdk-3 gio-2.0 glib-2.0 gobject-2.0 gtk-3
WANTLIB += gtksourceview-4 icui18n icuuc intl pango-1.0

COMPILER=		base-clang ports-gcc base-gcc

MODULES=		devel/meson \
			x11/gnome

MODGNOME_TOOLS= 	gobject-introspection

BUILD_DEPENDS=		devel/gsettings-desktop-schemas \
			textproc/gtk-doc

RUN_DEPENDS=		devel/gsettings-desktop-schemas

LIB_DEPENDS=		textproc/icu4c \
			x11/gnome/amtk \
			x11/gtksourceview4

DEBUG_PACKAGES=		${BUILD_PACKAGES}

.include <bsd.port.mk>
