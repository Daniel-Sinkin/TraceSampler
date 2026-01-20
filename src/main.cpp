// main.cpp
#include "pch.hpp" // IWYU pragma: keep
#include <print>
#include <string>
#include <string_view>
//
using usize = std::size_t;
using f32 = float;
using f64 = double;

enum class Kind {
    Begin,
    End,
};

struct Event {
    Kind Type;
    double Elapsed;
    std::string Method;
};
using Events = std::vector<Event>;

struct Sample {
    double Elapsed;
    std::vector<std::string> Stack;
};
using Samples = std::vector<Sample>;

Events GenerateEvents(const Samples &samples) {
    (void)samples;
    return {};
}

Samples get_example_samples() {
    return {
        {2.4, {"main"}},
        {2.5, {
                  "main",
                  "foo",
                  "bar",
              }},
        {2.6, {
                  "main",
                  "bar",
                  "foo",
              }},
        {3.0, {
                  "main",
              }},
    };
}
std::string to_string(const Sample &sample) {
    return std::format("[{}, {}]", sample.Elapsed, sample.Stack);
}

std::string to_string(const Samples &samples) {
    std::string out{};
    for (const Sample &sample : samples) {
        out += to_string(sample) + "\n";
    }
    return out;
}

void print(const Sample &sample) {
    std::println("{}", to_string(sample));
}

void print(const Samples &samples) {
    std::println("{}", to_string(samples));
}

int main() {
    const Samples samples{{2.4, {"main"}}, {3.0, {}}};

    std::vector<std::string> callstack{};

    for (usize i{0zu}; i < samples.size(); ++i) {
        const Sample &sample{samples[i]};
        [[maybe_unused]] const f64 elapsed = sample.Elapsed;
        const std::vector<std::string> &sstack = sample.Stack;

        // Skip while similiar
        for (usize j{0zu}; j < sstack.size(); ++j) {
        }
    }
}
