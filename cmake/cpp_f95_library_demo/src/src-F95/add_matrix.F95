subroutine add_matrix_2d(nrow,ncol,A,B,C) bind(C,name="add_matrix_")
    use iso_c_binding
    implicit none

    integer*4, intent(in)  :: nrow
    integer*4, intent(in)  :: ncol
    real*8,    intent(in)  :: A(nrow,ncol)
    real*8,    intent(in)  :: B(nrow,ncol)
    real*8,    intent(out) :: C(nrow,ncol)

    integer*4 :: i,j

    do j = 1,nrow
    do i = 1,ncol
        C(i,j) = A(i,j) + B(i,j)
    end do
    end do
end subroutine
