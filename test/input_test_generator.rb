require 'pp'

puts "write test_cases.h"
out = File.open('test_cases.h', 'w')
out.write "namespace #{ARGV[1]} {\n#include \"main.cpp\"\n}\n"
Dir.glob('input.*.txt') do |f|
  test_no = File.basename(f).scan(/input\.([0-9]+)\.txt/)[0][0]
  out.write "DEFINE_INPUT_TEST(#{ARGV[0]}, #{ARGV[1]}, #{test_no})\n"
end

