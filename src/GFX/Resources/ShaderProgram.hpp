#pragma once

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

namespace GLSLShader {
    enum ShaderType
    {
        VERTEX,
        FRAGMENT,
        GEOMETRY,
        TESS_CONTROL,
        TESS_EVALUATION,
        COMPUTE
    };
}
class ShaderProgram
{
public: 
	bool Link();
	bool Validate();

    std::string Log() const;

	void Use() const;	

	bool CompileShaderFromFile(const char* fileName, GLSLShader::ShaderType type);
    bool CompileShaderFromString(const std::string& source, GLSLShader::ShaderType type);

    static ShaderProgram* CreateShaderProgram(const std::string& vertShader,
        const std::string& fragShader);

    // SET UNIFORM WITH NAMES (FIND LOCATION) == slower
    void SetUniform(const std::string& name, float x, float y, float z) const;
    void SetUniform(const std::string& name, const glm::vec2& v) const;
    void SetUniform(const std::string& name, const glm::vec3& v) const;
    void SetUniform(const std::string& name, const glm::vec4& v) const;
    void SetUniform(const std::string& name, const glm::mat4& m) const;
    void SetUniform(const std::string& name, const glm::mat3& m) const;
    void SetUniform(const std::string& name, float val) const;
    void SetUniform(const std::string& name, int val) const;
    void SetUniform(const std::string& name, bool val) const;
    void SetSubroutineUniform(const std::string& name, const std::string& funcName) const;

    // SET UNIFORM WITH LOCATIONS
    void SetUniform(int loc, float x, float y, float z) const;
    void SetUniform(int loc, const glm::vec2& v) const;
    void SetUniform(int loc, const glm::vec3& v) const;
    void SetUniform(int loc, const glm::vec4& v) const;
    void SetUniform(int loc, const glm::mat4& m) const;
    void SetUniform(int loc, const glm::mat3& m) const;
    void SetUniform(int loc, float val) const;
    void SetUniform(int loc, int val) const;
    void SetUniform(int loc, bool val) const;

    bool IsLinked();
private:
    bool FileExists(const std::string& fileName);
    int  GetUniformLocation(const std::string& name) const;

    int         handle_ = -1;
    bool        linked_ = false;
    std::string log_string_ = "";
};
