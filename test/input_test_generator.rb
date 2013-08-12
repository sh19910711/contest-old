require 'pp'

testname = File.basename(Dir.pwd)
namespace = File.basename(File.expand_path("..", Dir.pwd))

puts "write test_cases.h"
out = File.open('test_cases.h', 'w')
out.write "namespace #{testname} {\n#include \"main.cpp\"\n}\n"
Dir.glob('input.*.txt') do |f|
  test_no = File.basename(f).scan(/input\.([0-9]+)\.txt/)[0][0]
  out.write "DEFINE_INPUT_TEST(#{namespace}, #{testname}, #{test_no})\n"
end

