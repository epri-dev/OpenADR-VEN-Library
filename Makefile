.DEFAULT_GOAL := all

DOCKER_EXTRA_ARGS ?=

export DOCKER_BUILDKIT ?= 1

define BUILDER
	docker container run \
		--env CCACHE_DIR=/openadr-ven-library/.ccache \
		--init \
		--rm \
		--volume "$(shell pwd)":/openadr-ven-library/ \
		--user $(shell id -u):$(shell id -g) \
		--workdir /openadr-ven-library/ \
		$(DOCKER_EXTRA_ARGS) \
		analyticsfire/openadr-ven-library-builder
endef

.PHONY: all
all: build

.PHONY: build
build: builder
	$(BUILDER) cmake -B build -DTEST=1 -DCOVERAGE=1
	$(BUILDER) cmake --build build --parallel $(shell nproc)

.PHONY: builder
builder:
	docker image build --target builder --tag analyticsfire/openadr-ven-library-builder - < Dockerfile

.PHONY: clean
clean:
	rm -rf build

.PHONY: prune
prune: | clean
	docker image rm analyticsfire/openadr-ven-library-builder || true

.PHONY: shell
shell: DOCKER_EXTRA_ARGS = --interactive --tty
shell: | builder
	$(BUILDER)

.PHONY: test
test:
	$(BUILDER) /bin/bash -c "cd build && ./testoadr"

.PHONY: coverage
coverage:
	rm -rf build/coverage
	mkdir -p build/coverage
	$(BUILDER) gcovr
