
#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
    char* data;
    size_t size;

    void copy_data(const char* s) {
        size = std::strlen(s);
        data = new char[size + 1];
        std::strcpy(data, s);
    }

public:
    str() : data(new char[1]), size(0) {
        data[0] = '\0';
    }

    str(const char &c) : data(new char[2]), size(1) {
        data[0] = c;
        data[1] = '\0';
    }

    str(const char *&& s_) : data(nullptr), size(0) {
        if (s_) {
            copy_data(s_);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    str &operator=(const char *&& s_) {
        if (data) {
            delete[] data;
        }
        if (s_) {
            copy_data(s_);
        } else {
            data = new char[1];
            data[0] = '\0';
            size = 0;
        }
        return *this;
    }

    str(const str &other) : data(nullptr), size(0) {
        if (other.data) {
            copy_data(other.data);
        }
    }

    str &operator=(const str &other) {
        if (this != &other) {
            if (data) {
                delete[] data;
            }
            if (other.data) {
                copy_data(other.data);
            } else {
                data = new char[1];
                data[0] = '\0';
                size = 0;
            }
        }
        return *this;
    }

    char &operator[](size_t pos) {
        return data[pos];
    }

    size_t len() const {
        return size;
    }

    str join(const std::vector<str> &strs) const {
        if (strs.empty()) {
            return str();
        }
        
        // Calculate total length needed
        size_t total_len = 0;
        for (size_t i = 0; i < strs.size(); ++i) {
            total_len += strs[i].len();
            if (i < strs.size() - 1) {
                total_len += len();  // Add separator length
            }
        }
        
        // Create result string
        str result;
        delete[] result.data;
        result.data = new char[total_len + 1];
        result.size = total_len;
        result.data[total_len] = '\0';
        
        char* ptr = result.data;
        for (size_t i = 0; i < strs.size(); ++i) {
            // Copy string
            std::strcpy(ptr, strs[i].data);
            ptr += strs[i].len();
            
            // Add separator if not the last string
            if (i < strs.size() - 1) {
                std::strcpy(ptr, data);
                ptr += len();
            }
        }
        
        return result;
    }

    str slice(size_t l, size_t r) const {
        // Clamp r to size if it's too large
        if (r > size) {
            r = size;
        }
        
        // Handle invalid range
        if (l >= r || l >= size) {
            return str();
        }
        
        // Create new string with the slice
        str result;
        delete[] result.data;
        size_t slice_len = r - l;
        result.data = new char[slice_len + 1];
        result.size = slice_len;
        std::strncpy(result.data, data + l, slice_len);
        result.data[slice_len] = '\0';
        
        return result;
    }

    ~str() {
        delete[] data;
    }
};
