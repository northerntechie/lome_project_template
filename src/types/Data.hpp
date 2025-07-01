/**
 * Lome sample project - AlgorithmLibrary
 *
 */
#include <ostream>
#include <string_view>

struct Data {
	std::string_view value;

	bool operator>(const Data& other) const {
		std::printf("\n%s > %s, returns %s\n", value.data(), other.value.data(), value > other.value ? "true" : "false");
		return value > other.value;
	}

	bool operator==(const Data& other) const {
		return value == other.value;
	}
	friend std::ostream& operator<<(std::ostream& os, const Data& data);
};

inline std::ostream& operator<<(std::ostream& os, const Data& data) {
	return os << data.value;
}