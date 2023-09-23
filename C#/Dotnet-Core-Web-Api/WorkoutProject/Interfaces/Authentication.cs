using WorkoutProject.Dtos;

namespace WorkoutProject.Services
{
    public interface IAuthenticationService
    {
        public Task<SignupResponseDto> SignUpAsync(SignupRequestDto request);
        public Task<LoginResponseDto> LoginAsync(LoginRequestDto request);
    }
}