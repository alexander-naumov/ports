COMMENT =		owncloud sync client

V = 			3.0.0.9215
DISTNAME =		ownCloud-${V}
PKGNAME =  		owncloudclient-${V}

SHARED_LIBS +=		owncloudsync		8.0
SHARED_LIBS +=		owncloud_csync		2.0
SHARED_LIBS +=		owncloudResources	0.0

CATEGORIES =		net

HOMEPAGE =		https://owncloud.com/desktop-app/

MAINTAINER =		Kirill Bychkov <kirby@openbsd.org>

# GPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB += Qt5Concurrent Qt5Core Qt5DBus Qt5Gui Qt5Network Qt5Widgets
WANTLIB += Qt5Xml c m qt5keychain sqlite3 z
WANTLIB += ${COMPILER_LIBCXX} lib/inotify/inotify

MASTER_SITES =		https://download.owncloud.com/desktop/ownCloud/stable/latest/source/ \
			https://download.owncloud.com/desktop/ownCloud/stable/${V}/source/
EXTRACT_SUFX =		.tar.xz

MODULES =		devel/cmake x11/qt5

BUILD_DEPENDS = 	devel/kf5/extra-cmake-modules
RUN_DEPENDS =		devel/desktop-file-utils \
			misc/shared-mime-info \
			x11/gtk+3,-guic
LIB_DEPENDS =		databases/sqlite3 \
			devel/libinotify \
			security/qtkeychain

CONFIGURE_ARGS +=	-Wno-dev \
			-DSYSCONF_INSTALL_DIR=${SYSCONFDIR} \
			-DKDE_INSTALL_PLUGINDIR=${PREFIX}/lib/ownCloud/plugins/ \
			-DCMAKE_DISABLE_FIND_PACKAGE_KF5=TRUE \
			-DCMAKE_DISABLE_FIND_PACKAGE_CMocka=TRUE \
			-DCSYNC_REQUIRED_LIBRARIES=c \
			-DWITH_AUTO_UPDATER=FALSE \
			-DWITH_LIBCLOUDPROVIDERS=FALSE

CFLAGS +=	-I${LOCALBASE}/include -I${LOCALBASE}/include/qtkeychain
CXXFLAGS +=	-I${LOCALBASE}/include -I${LOCALBASE}/include/qtkeychain
MODCMAKE_LDFLAGS =	-L${LOCALBASE}/lib

NO_TEST =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ownCloud/
	mv ${WRKINST}/etc/ownCloud ${PREFIX}/share/examples/

.include <bsd.port.mk>
