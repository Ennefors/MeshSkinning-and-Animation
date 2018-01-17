file(REMOVE_RECURSE
  "../../../bin/Mathlib.pdb"
  "../../../bin/Mathlib"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Mathlib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
