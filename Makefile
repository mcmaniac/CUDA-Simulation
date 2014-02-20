CC = nvcc
CFLAGS = -arch=sm_35

.PHONY: all

CXX_SRCS  = particle.cpp\
						simulation.cpp
CUDA_SRCS = cuda/simulation.cu\
						cuda/prediction_step.cu

all:
	$(CC) $(CFLAGS) $(CXX_SRCS) $(CUDA_SRCS) main.cpp
	./a.out
