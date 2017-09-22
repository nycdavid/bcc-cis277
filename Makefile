run:
	docker run \
	-it \
	-v $(shell pwd)/src:/app/src \
	-v $(shell pwd)/output:/test_bin \
	--rm \
	davidko/cpp-env:base \
	/bin/ash -c "touch /test_bin/output.txt && g++ -std=c++14 -o /test_bin/program /app/src/${WEEK}/execute.cc && /test_bin/program"

test:
	docker run \
	-it \
	-v $(shell pwd)/src:/app/src \
	-v $(shell pwd)/tests:/app/tests \
	--rm \
	cpp-env:1.0.0 \
	/bin/bash -c "g++ -std=c++14 -o /test_bin/some_test /app/tests/week*/* /app/src/week*/* && /test_bin/some_test"
