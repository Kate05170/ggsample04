//
// �P�ʍs���ݒ肷��
//
//   m: �P�ʍs���ݒ肷��z��ϐ�
//
extern void loadIdentity(GLfloat *m);

//
// ���𓊉e�ϊ��s������߂�
//
//   m: ���𓊉e�ϊ��s����i�[����z��
//   left, right: �r���[�{�����[���̍��E�[
//   bottom, top: �r���[�{�����[���̏㉺�[
//   zNear, zFar: �O���ʂ���ь���ʂ܂ł̋���
//
extern void ortho(GLfloat *m, float left, float right, float bottom, float top, float zNear, float zFar);

//
// �������e�ϊ��s������߂�
//
//   m: �������e�ϊ��s����i�[����z��
//   left, right: �O���ʂ̍��E�[
//   bottom, top: �O���ʂ̏㉺�[
//   zNear, zFar: �O���ʂ���ь���ʂ܂ł̋���
//
extern void frustum(GLfloat *m, float left, float right, float bottom, float top, float zNear, float zFar);

//
// ��p���w�肵�ē������e�ϊ��s������߂�
//
//   m: �������e�ϊ��s����i�[����z��
//   fovy: ��p�i���W�A���j
//   aspect: �E�B���h�E�̏c����
//   zNear, zFar: �O���ʂ���ь���ʂ܂ł̋���
//
extern void perspective(GLfloat *m, float fovy, float aspect, float zNear, float zFar);

//
// �r���[�ϊ��s������߂�
//
//   m: �r���[�ϊ��s����i�[����z��
//   ex, ey, ez: ���_�̈ʒu
//   tx, ty, tz: �ڕW�_�̈ʒu
//   ux, uy, uz: ������̃x�N�g��
//
extern void lookat(GLfloat *m, float ex, float ey, float ez, float tx, float ty, float tz, float ux, float uy, float uz);

//
// ���s�ړ��ϊ��s������߂�
//
//   m: ���s�ړ��ϊ��s����i�[����z��
//   x, y, z: ���s�ړ���
//
extern void translate(GLfloat *m, float x, float y, float z);

//
// �g��k���ϊ��s������߂�
//
//   m: ���s�ړ��ϊ��s����i�[����z��
//   x, y, z: �g��k����
//
extern void scale(GLfloat *m, float x, float y, float z);

//
// �C�ӎ�����̉�]�ϊ��s������߂�
//
//   r: ��]�ϊ��s����i�[����z��
//   x, y, z: ���S��
//   a: ��]�p�i���W�A���j
//
extern void rotate(GLfloat *r, float x, float y, float z, float a);

//
// �@���ϊ��s������߂�
//
//   g: �@���x�N�g���̕ϊ��s����i�[����z��
//   m: ���̕ϊ��s��
//
extern void normal(GLfloat *g, const float *m);

//
// �t�s������߂�
//
//   m1: ���̕ϊ��s��
//   m2: m1 �̋t�s��
//   �t�s�񂪋��߂��Ȃ���Ζ߂�l�� false
//
extern bool inverse(GLfloat *m2, const GLfloat *m1);

//
// 4 �s 4 ��̍s��̐ς����߂�
//
//   m �� m1 �~ m2
//
extern void multiply(GLfloat *m, const GLfloat *m1, const GLfloat *m2);

//
// �x�N�g���ɍs���������
//
//   v2 �� m * v1
//
extern void transform(GLfloat *v2, const GLfloat *m, const GLfloat *v1);

//
// �x�N�g�� v1 �𐳋K���������̂����߂�
//
//   v2 �� v1 �𐳋K��
//
extern void normalize(GLfloat *v2, const GLfloat *v1);
