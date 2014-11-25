select 
B.fd_author_id AS '�û���id',
CONCAT(B.fd_author_truename, '-', B.fd_author_username) AS '�û�����',
A.fd_tfmglist_fucardno AS '�����',
A.fd_tfmglist_fucardbank AS '�������',
A.fd_tfmglist_shoucardno AS '�տ��',
A.fd_tfmglist_shoucardman AS '�տ�������',
A.fd_tfmglist_paydate AS '��������',
A.fd_tfmglist_paymoney AS '���׽��',
A.fd_tfmglist_payfee as '����������' 
FROM 
tb_transfermoneyglist AS A LEFT JOIN tb_author AS B
 ON A.fd_tfmglist_authorid = B.fd_author_id 
WHERE  fd_tfmglist_paydate >= '2014-10-01' AND fd_tfmglist_paydate<= '2014-10-31'
 ORDER BY A.fd_tfmglist_paydate asc