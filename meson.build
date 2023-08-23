project('casefolding-bench', 'c', 'cpp', meson_version: '>=0.58.0' )

benchmark_dep = dependency('benchmark')

src = ['utf8-core.c', 'utf8-norm.c', 'utf8data.c', 'test_cpp_helpers.c', 'main.cpp']

executable('casefolding_bench', src,
        dependencies : [ benchmark_dep ]
)