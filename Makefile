run:
	docker run \
	-it \
	-v $(shell pwd)/src:/app/src \
	--rm \
	cpp-env:1.0.0 \
	/bin/bash -c "touch output.txt && g++ -std=c++14 -o /test_bin/program /app/src/${WEEK}/execute.cc && /test_bin/program && cat output.txt"

test:
	docker run \
	-it \
	-v $(shell pwd)/src:/app/src \
	-v $(shell pwd)/tests:/app/tests \
	--rm \
	cpp-env:1.0.0 \
	/bin/bash -c "g++ -std=c++14 -o /test_bin/some_test /app/tests/week*/* /app/src/week*/* && /test_bin/some_test"
