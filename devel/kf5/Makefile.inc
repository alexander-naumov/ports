CATEGORIES +=		devel devel/kf5

VERSION ?=		${MODKF5_VERSION}
MAINTAINER ?=		Rafael Sadowski <rsadowski@openbsd.org>
HOMEPAGE ?=		https://projects.kde.org/projects/frameworks/${DISTNAME:C/-[0-9].*//}

# usual KDE rules:
# LGPLv2.1+, GPLv2+
PERMIT_PACKAGE =	Yes

CONFIGURE_STYLE ?=	cmake
MODULES :=		devel/kf5 ${MODULES}

IS_PORTING_AID ?=	No
.if ${IS_PORTING_AID:L} == "yes"
MASTER_SITES ?=		${MASTER_SITE_KDE:=stable/frameworks/${VERSION:R}/portingAids/}
.else
MASTER_SITES ?=		${MASTER_SITE_KDE:=stable/frameworks/${VERSION:R}/}
.endif

DIST_SUBDIR =		kde
