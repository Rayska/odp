ODP_MODULES = align \
	      atomic \
	      barrier \
	      buffer \
	      byteorder \
	      chksum \
	      classification \
	      comp \
	      cpu \
	      cpumask \
	      crypto \
	      dma \
	      errno \
	      event \
	      hash \
	      hints \
	      init \
	      ipsec \
	      lock \
	      ml \
	      queue \
	      packet \
	      pktio \
	      pool \
	      random \
	      scheduler \
	      stash \
	      std \
	      thread \
	      time \
	      timer \
	      traffic_mngr \
	      shmem \
	      system

SUBDIRS = $(ODP_MODULES)

include $(top_srcdir)/test/Makefile.inc
TESTS_ENVIRONMENT += TEST_DIR=${top_builddir}/test/validation/api

TESTS = \
	align/align_main$(EXEEXT) \
	atomic/atomic_main$(EXEEXT) \
	event/event_main$(EXEEXT)

TESTNAME = validation

TESTENV = tests-$(TESTNAME).env

test_DATA = $(TESTENV)

DISTCLEANFILES = $(TESTENV)
.PHONY: $(TESTENV)
$(TESTENV):
	echo "TESTS=\"$(TESTS)\""    > $@
	echo "$(TESTS_ENVIRONMENT)" >> $@
	echo "$(LOG_COMPILER)"      >> $@

.NOTPARALLEL:
