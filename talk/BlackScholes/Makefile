all:
	icc -O3 01_CheckCorrectness.cpp -o 01_CheckCorrectness
	icc -O3 -openmp -xhost 02_ReferenceVersion.cpp -o 02_ReferenceVersion
	icc -O3 -openmp -xhost 03_DoNotMixDataTypes.cpp -o 03_DoNotMixDataTypes
	icc -O3 -openmp -xhost 04_VectorizeLoops.cpp -o 04_VectorizeLoops
	icc -O3 -openmp -xhost 05_UseFastMathFunctions.cpp -o 05_UseFastMathFunctions
	icc -O3 -openmp -xhost 06_EquivalentTransformations.cpp -o 06_EquivalentTransformations
	icc -O3 -openmp -xhost 07_AlignArrays.cpp -o 07_AlignArrays
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 08_ReducePrecision.cpp -o 08_ReducePrecision
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 09_WorkInParallel.cpp -o 09_WorkInParallel -g -qopt-report5
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 10_UseWarmUp.cpp -o 10_UseWarmUp
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 11_XeonPhi.cpp -o 11_XeonPhi
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 12_XeonPhiWorkInParallel.cpp -o 12_XeonPhiWorkInParallel
	icc -O3 -openmp -xhost -fimf-precision=low -fimf-domain-exclusion=31 13_XeonPhiStreamingStores.cpp -o 13_XeonPhiStreamingStores


clean:
	rm -f 01_CheckCorrectness 02_ReferenceVersion 03_DoNotMixDataTypes 04_VectorizeLoops 05_UseFastMathFunctions 06_EquivalentTransformations 07_AlignArrays 08_ReducePrecision 09_WorkInParallel 10_UseWarmUp 11_XeonPhi 12_XeonPhiWorkInParallel 13_XeonPhiStreamingStores

run01:
	./01_CheckCorrectness 60000000

run02:
	./02_ReferenceVersion 60000000

run03:
	./03_DoNotMixDataTypes 60000000

run04:
	./04_VectorizeLoops 60000000

run05:
	./05_UseFastMathFunctions 60000000

run06:
	./06_EquivalentTransformations 60000000

run07:
	./07_AlignArrays 60000000

run08:
	./08_ReducePrecision 60000000

run09:
	./09_WorkInParallel 60000000 16

run10:
	./10_UseWarmUp 60000000 16

run11:
	./11_XeonPhi 60000000 16

run12:
	./12_XeonPhiWorkInParallel 60000000 16

run13:
	./13_XeonPhiStreamingStores 60000000 16
