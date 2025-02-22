VERSION =		3.2.0
DISTNAME =		ruby-${VERSION}
SHARED_LIBS =		ruby32	0.0
NEXTVER =		3.3
PKGSPEC-main ?=         ruby->=3.2.0,<${NEXTVER}
REVISION-main =		0

PSEUDO_FLAVORS=		no_ri_docs bootstrap
# Do not build the RI docs on slow arches
.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Marm} || ${MACHINE_ARCH:Mhppa}
FLAVOR?=		no_ri_docs bootstrap
.else
FLAVOR?=
.endif

.if ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Maarch64}
# Support YJIT JIT compiler on arches Ruby supports
BUILD_DEPENDS +=	lang/rust
WANTLIB-main +=		c++abi
.endif

MULTI_PACKAGES =	-main -ri_docs
.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-ri_docs}
ALL_TARGET +=		rdoc
INSTALL_TARGET +=	install-doc
.endif

COMPILER =      base-clang ports-gcc

# Fix path for JIT compiler to not use shims in ports obj bin dir
CONFIGURE_ENV +=	ac_cv_path_MJIT_CC=`which ${CC}`

GEM_EXTENSIONS_DIR = lib/ruby/gems/${REV}/extensions/${MACHINE_ARCH:S/i386/x86/:S/amd64/x86_64/}-openbsd
SUBST_VARS += GEM_EXTENSIONS_DIR

WANTLIB-main +=	curses yaml-0

post-extract:
	${POST_EXTRACT}

pre-configure:
	${FIX_RIPPER}

pre-install:
	${PRE_INSTALL}

post-install:
	${FIX_RBCONFIG}

do-test:
	cd ${WRKSRC} && make check

.include <bsd.port.mk>
