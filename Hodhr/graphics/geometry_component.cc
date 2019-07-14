//
//  geometry_component.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "geometry_component.h"
#include "renderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace hodhr {
namespace graphics {
    
    static const GLfloat g_vertex_buffer_data[] = {
      -1.0f,-1.0f,-1.0f, // triangle 1 : begin
      -1.0f,-1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, // triangle 1 : end
      1.0f, 1.0f,-1.0f, // triangle 2 : begin
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f, // triangle 2 : end
      1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      1.0f,-1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f,-1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f,
      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f,-1.0f, 1.0f
    };
    
    void GeometryComponent::Init() {
      glGenBuffers(1, &vertex_array);
      glBindVertexArray(vertex_array);
      
      glGenBuffers(1, &vertex_buffer);
      glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
      glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
      
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(
                            0,
                            3,
                            GL_FLOAT,
                            GL_FALSE,
                            0,
                            (void*)0
                            );
      
    }
    
    void GeometryComponent::Draw(graphics::Renderer * renderer) {
      
      // set the physical shader
      auto physical_shader = renderer->PhysicalShader();
      physical_shader->Use();
      auto mvp_location = physical_shader->UniformLocation("MVPMatrix");
      auto model_matrix = parent_->ModelMatrix();
      auto view_matrix = renderer->CurrentScene()->GetCamera()->ViewMatrix();
      auto projection_matrix = renderer->CurrentScene()->GetCamera()->ProjectionMatrix();
      auto MVPMatrix = projection_matrix * view_matrix * model_matrix;
      
      glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(MVPMatrix));
      glBindVertexArray(vertex_array);
      glDrawArrays(GL_TRIANGLES, 0, 12*3);
      glBindVertexArray(0);
    }
    
    GeometryComponent::~GeometryComponent() {
      glDeleteBuffers(1, &vertex_buffer);
      glDeleteVertexArrays(1, &vertex_array);
    }
    
  }
}
