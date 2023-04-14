#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct ShaderProgramSource {
    std::string VertexShaderSource;
    std::string FragmentShaderSource;
};

class Shader
{
private:
    unsigned int _renderID;
    std::string _filePath;
    std::unordered_map<std::string, int> _uniformLocationCache;
public:

    Shader(const std::string& filePath);

    ~Shader();

    void Bind() const;

    void Unbind() const;

    //Set Uniforms
    void SetUniform4f(const std::string& name, const glm::mat4& matrix);
    

private:
    ShaderProgramSource ParseShader(const std::string& filePath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    unsigned int GetUniformLocation(const std::string& name);
};