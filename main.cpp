// �E�B���h�E�֘A�̏���
#include "Window.h"

// �V�F�[�_�[�֘A�̏���
#include "shader.h"

// �I�u�W�F�N�g�֘A�̏���
#include "object.h"

// �ϊ��s��֘A�̏���
#include "matrix.h"

// Catmull-Rom �X�v���C��
#include "spline.h"

// �W�����C�u����
#include <cmath>

// �A�j���[�V�����̎����i�b�j
const double cycle(5.0);

//
// ���C���v���O����
//
int main()
{
  // �E�B���h�E���쐬����
  Window window("ggsample04");

  // �w�i�F���w�肷��
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  // �v���O�����I�u�W�F�N�g�̍쐬
  const GLuint program(loadProgram("simple.vert", "pv", "simple.frag", "fc"));

  // uniform �ϐ��̃C���f�b�N�X�̌����i������Ȃ���� -1�j
  const GLint mcLoc(glGetUniformLocation(program, "mc"));

  // �r���[�ϊ��s��� mv �ɋ��߂�
  GLfloat mv[16];
  lookat(mv, 3.0f, 4.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

  // ���_����
  static const GLfloat position[][3] =
  {
    { -0.9f, -0.9f, -0.9f },  // (0)
    {  0.9f, -0.9f, -0.9f },  // (1)
    {  0.9f, -0.9f,  0.9f },  // (2)
    { -0.9f, -0.9f,  0.9f },  // (3)
    { -0.9f,  0.9f, -0.9f },  // (4)
    {  0.9f,  0.9f, -0.9f },  // (5)
    {  0.9f,  0.9f,  0.9f },  // (6)
    { -0.9f,  0.9f,  0.9f },  // (7)
  };
  static const int vertices(sizeof position / sizeof position[0]);

  // ���_�C���f�b�N�X
  static const GLuint index[] =
  {
    0, 1,
    1, 2,
    2, 3,
    3, 0,
    0, 4,
    1, 5,
    2, 6,
    3, 7,
    4, 5,
    5, 6,
    6, 7,
    7, 4,
  };
  static const GLuint lines(sizeof index / sizeof index[0]);

  // ���_�z��I�u�W�F�N�g�̍쐬
  const GLuint vao(createObject(vertices, position, lines, index));

  // ���s�ړ��̌o�H
  static const float route[][3] =
  {
    { -2.0f, -1.0f, -3.0f },
    {  0.0f, -2.0f, -2.0f },
    { -1.0f, -1.0f, -1.0f },
    { -0.5f, -0.5f, -0.5f },
    {  0.0f,  0.0f,  0.0f },
  };

  // �ʉߎ��� (�~ cycle)
  static const float transit[] =
  {
    0.0f,
    0.3f,
    0.5f,
    0.7f,
    1.0f,
  };

  // �ʉߒn�_�̐�
  static const int points(sizeof transit / sizeof transit[0]);

  // �o�ߎ��Ԃ̃��Z�b�g
  glfwSetTime(0.0);

  // �E�B���h�E���J���Ă���ԌJ��Ԃ�
  while (window.shouldClose() == GL_FALSE)
  {
    // �E�B���h�E����������
    glClear(GL_COLOR_BUFFER_BIT);

    // �V�F�[�_�v���O�����̎g�p�J�n
    glUseProgram(program);

    // �����̌v��
    const float t(static_cast<float>(fmod(glfwGetTime(), cycle) / cycle));

    // ���� t �ɂ��ƂÂ���]�A�j���[�V����
    GLfloat mr[16];                   // ��]�̕ϊ��s��
    // �y�h��z�������𓚂��Ă��������i���� loadIdentity() ��u�������Ă��������j
    loadIdentity(mr);

    // ���� t �ɂ��ƂÂ����s�ړ��A�j���[�V����
    float location[3];                // ���݈ʒu
    spline(location, route, transit, points, t);
    GLfloat mt[16];                   // ���s�ړ��̕ϊ��s��
    translate(mt, location[0], location[1], location[2]);

    // ���f���ϊ��s��� mm �ɋ��߁C
    // ����ƃr���[�ϊ��s�� mv �̐ς����f���r���[�ϊ��s�� mw �ɋ��߂�
    GLfloat mm[16], mw[16];
    multiply(mm, mt, mr);             // ���f���ϊ� mm �� �ړ� mt �~ ��] mr
    multiply(mw, mv, mm);             // ���f���r���[�ϊ� mw �� �r���[�ϊ� mv �~ ���f���ϊ� mm

    // �������e�ϊ��s��� mp �ɋ��߁C
    // ����ƃ��f���r���[�ϊ��s�� mw �̐ς��N���b�s���O���W�n�ւ̕ϊ��s�� mc �ɋ��߂�
    GLfloat mp[16], mc[16];
    perspective(mp, 0.5f, window.getAspect(), 1.0f, 15.0f);
    multiply(mc, mp, mw);             // �N���b�s���O���W�n�ւ̕ϊ��s�� mc �� ���e�ϊ� mp �~ ���f���r���[�ϊ� mw

    // uniform �ϐ� mc �ɕϊ��s�� mc ��ݒ肷��
    glUniformMatrix4fv(mcLoc, 1, GL_FALSE, mc);

    // �`��Ɏg�����_�z��I�u�W�F�N�g�̎w��
    glBindVertexArray(vao);

    // �}�`�̕`��
    glDrawElements(GL_LINES, lines, GL_UNSIGNED_INT, 0);

    // ���_�z��I�u�W�F�N�g�̎w�����
    glBindVertexArray(0);

    // �V�F�[�_�v���O�����̎g�p�I��
    glUseProgram(0);

    // �J���[�o�b�t�@�����ւ��ăC�x���g�����o��
    window.swapBuffers();
  }
}
