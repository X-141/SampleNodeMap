#pragma once
#include <iostream>
#include <fstream>
#include <string>

/**
 *  Instance of a single file parser that will create a NodeMap 
 */
class Parser {
public:
    enum class FILE_STATUS
    {
        cUNINIT_STATUS,     // 0 No file handle operations have occurred
        cFILE_OPEN,         // 1 File handle is opened and does exist
        cFILE_UNAVAILABLE,  // 2 File handle was attempted to be opened, but failed
        cFILE_CLOSED        // 3 File handle was closed
    };

    Parser() = delete;

    /**
     * Constructor for the parser class. This constructor initializes the file handle for reading.
     *
     * @param t_file_path File path for the target source file to be parsed
     */
    explicit Parser(const std::string& t_file_path)
        : m_file_path(t_file_path), m_file_handle(std::fstream(m_file_path, std::ios::in))
        , m_status(FILE_STATUS::cUNINIT_STATUS)
    {
        if (m_file_handle.is_open())
            m_status = FILE_STATUS::cFILE_OPEN;
        else m_status = FILE_STATUS::cFILE_UNAVAILABLE;
    }

    /**
     * Destructor that will close and wrap up any parsing data
     *
     */
    ~Parser()
    {
        close_file();
    };

    /**
     * Helper function that will close file handle. Should be used in the destructor.
     *
     */
    void close_file()
    {
        m_file_handle.close();
        m_status = FILE_STATUS::cFILE_CLOSED;
    }

    FILE_STATUS get_status() const { return m_status; }

private:
    std::string m_file_path;    // stores the target source file path
    std::fstream m_file_handle; // stores the source file handle for reading
    FILE_STATUS m_status;       // specifies the current status of the parser
};