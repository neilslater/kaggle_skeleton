require "rspec/core/rake_task"
require 'rake/extensiontask'

# Insert project local lib folder into library search path
$: << File.join( File.dirname( __FILE__ ), 'lib' )

desc "Unit tests"
RSpec::Core::RakeTask.new(:test) do |t|
  t.pattern = "spec/*_spec.rb"
  t.verbose = true
end

Rake::ExtensionTask.new do |ext|
  ext.name = 'kaggle_skeleton'
  ext.source_pattern = "*.{c,h}"
  ext.ext_dir = 'ext/kaggle_skeleton'
  ext.lib_dir = 'lib/kaggle_skeleton'
end

desc "Import CSV"
task :import_csv do
  require 'kaggle_skeleton'
  if KaggleSkeleton.ready_to_run?
    puts "CSV data already imported."
  elsif KaggleSkeleton.ready_to_import?
    KaggleSkeleton.import_from_csv
  else
    puts ''
    puts '**********************************************************'
    puts ' Place Kaggle file data.csv in data directory'
    puts '**********************************************************'
    puts ''
    raise "Data file missing: #{KaggleSkeleton::CSV_PATH}"
  end
end

desc "Run solver and save submission"
task :solve do
  require 'kaggle_skeleton'
  unless KaggleSkeleton.ready_to_run?
    raise "Not ready, import CSV data first."
  end
  solver = KaggleSkeleton::Solver.new
  solver.run
  submission_file = File.join( KaggleSkeleton::DATA_PATH, 'submission.csv' )
  puts "Writing submission file: #{submission_file}"
  solver.submission.write_csv( submission_file )
end

task :default => [:compile, :import_csv, :test, :solve]
