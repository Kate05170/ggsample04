//
// �C�ӂ̐��̓_��� Catmull-Rom Spline �ɂ����
//
//   p: ��Ԃ���_��̍��W�l
//   t: ��Ԃ���_��̃^�C�����C���i�l�͏����Ɋi�[����Ă���j
//   n: �_�̐�
//   u: ��Ԓl�𓾂�p�����[�^ (t[0]��u��t[n - 1]�j
//
extern void spline(float *q, const float (*p)[3], const float *t, int n, float u);
