require 'pp'
require 'fileutils'

def remove_namespace (s, namespace)
  res = ""
  nest = 0
  s.each_line {|line|
    added = false
    if ( line.chomp.match(/{/) )
      if ( line.chomp.match(Regexp.new("namespace\s*" + namespace, 'i')) )
        nest += 1
      elsif ( nest == 0 )
        res += line unless added
        added = true
      elsif ( nest > 0 )
        nest += 1
      end
    end
    if ( nest > 0 && line.chomp.match(/}/) )
      nest -= 1
    else
      res += line unless added if nest == 0
      added = true
    end
  }
  return res
end

def remove_headers(s) 
  res = ""
  s.each_line {|line|
    res += line unless line.match(/^#include/) 
  }
  return res
end

def rename_streams (s)
  regexp_cin = Regexp.new("std::cin\s*>>")
  regexp_cout = Regexp.new("std::cout\s*<<")
  s.gsub!(regexp_cin, '*istream_pointer >>')
  s.gsub!(regexp_cout, '*ostream_pointer <<')
  s
end

current_dir = Dir.pwd
dir = ARGV[0]
to_dir = ARGV[1]
Dir.chdir dir
pp File.basename(Dir.pwd)

begin
  Dir.mkdir current_dir + '/' + to_dir
rescue
end

File.open('main.cpp') do |f|
  contents = f.read
  new_contents = remove_namespace(contents, ARGV[2])
  new_contents = remove_headers(new_contents)
  new_contents = rename_streams(new_contents)
  new_contents = "namespace solution {\n  std::istream* istream_pointer = &std::cin;\n  std::ostream* ostream_pointer = &std::cout;\n}\n" + new_contents
  File.open(current_dir + '/' + to_dir + '/main.cpp', 'w') {|f|
    f.write(new_contents)
  }
end

Dir.glob(['input.*.txt', 'expected.*.txt']) do |f| 
  pp f
  FileUtils.cp(f, current_dir + '/' + to_dir + '/' + f)
end

