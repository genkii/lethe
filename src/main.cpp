#include <CLI/CLI.hpp>
#include <filesystem>
#include <lethe/interpreter/runtime.hpp>

int main(int argc, char** argv)
{

    CLI::App app{"Lethe programming language"};
    app.set_version_flag("--version", "Lethe 0.1.0");

    std::filesystem::path filepath;

    auto run = app.add_subcommand("run", "Execute a Lethe bytecode file");

    run->add_option("file", filepath, "Bytecode file to execute")->required();

    CLI11_PARSE(app, argc, argv);

    if (*run)
    {
        Runtime runtime(filepath);
        runtime.start();
    }

    return 0;
}