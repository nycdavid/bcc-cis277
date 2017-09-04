test:
	docker run \
	-it \
	-v $(shell pwd)/src:/app/src \
	-v $(shell pwd)/tests:/app/tests \
	--rm \
	cpp-env:1.0.0 \
	/bin/bash -c "g++ -std=c++14 -o /test_bin/some_test /app/tests/week*/* /app/src/week*/* && /test/some_test"
